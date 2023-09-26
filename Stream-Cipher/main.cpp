#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

#define ENCRYPT_SYSTEM_NAME "encrypt"
#define DECRYPT_SYSTEM_NAME "decrypt"
#define SIMPLE_KIND_NAME "simple"
#define COMPLICATED_KIND_NAME "complicated"
#define MAX_RANDOM 11
#define GET_ENTER '\0'


struct Method {
    string system_name;
    string kind_name;
};

struct Path {
    string input_file_path;
    string output_file_path;
};

typedef vector<int> cipher_t;
typedef vector<char> text_t;


Method get_method();
string get_key();
Path get_files_path();
void process_output(Method method, string key, Path path);
void process_encryption_method_kind(Method method, string key, Path path);
void process_decryption_method_kind(Method method, string key, Path path);
vector<int> generate_key_for_simple_kind(string key, int input_size);
int create_random_seed(string key);
vector<int> generate_random_key(int input_size);
text_t read_file_encryption(string input_path);
cipher_t read_file_decryption(string input_path);
cipher_t encryption_action(text_t input, vector<int> key);
void encrypt_simple(string key, Path path, text_t input);
void encrypt_complicated(string key, Path path, text_t input);
text_t decryption_action(cipher_t input, vector<int> key);
void decrypt_simple(string key, Path path, cipher_t input);
void decrypt_complicated(string key, Path path, cipher_t input);
void create_output_file_enc(cipher_t output, int input_size, string output_path);
void create_output_file_dec(text_t output, int input_size, string output_path);

int main()
{
    Method method = get_method();
    string key = get_key();
    Path path = get_files_path();
    process_output(method, key, path);
}

Method get_method()
{
    Method method;
    cin >> method.system_name >> method.kind_name;

    return method;
}

string get_key()
{
    string key;
    cin >> key;
    
    return key;
}

Path get_files_path()
{
    Path path;
    cin >> path.input_file_path >> path.output_file_path;
    
    return path;
}

void process_output(Method method, string key, Path path)
{
    if (method.system_name == ENCRYPT_SYSTEM_NAME)
		process_encryption_method_kind(method, key, path);

	else if (method.system_name == DECRYPT_SYSTEM_NAME)
		process_decryption_method_kind(method, key, path);
}

void process_encryption_method_kind(Method method, string key, Path path)
{
    text_t input = read_file_encryption(path.input_file_path);
	
    if (method.kind_name == SIMPLE_KIND_NAME)
        encrypt_simple(key, path, input);
    
    else if (method.kind_name == COMPLICATED_KIND_NAME)
        encrypt_complicated(key, path, input);
}

void process_decryption_method_kind(Method method, string key, Path path)
{
    cipher_t input = read_file_decryption(path.input_file_path);
    
    if (method.kind_name == SIMPLE_KIND_NAME)
        decrypt_simple(key, path, input);
        
    else if (method.kind_name == COMPLICATED_KIND_NAME)
        decrypt_complicated(key, path, input);
}



vector<int> generate_key_for_simple_kind(string key, int input_size)
{
    vector<int> generated_key;
    for (int i = 0; i < input_size; ++i)
    {
        int key_index = i % key.size();
        int key_block = int(key[key_index]);
		generated_key.push_back(key_block);
    }
	return generated_key;
}

int create_random_seed(string key) 
{
    int random_seed = 0;
	for (int i = 0; i < key.size(); ++i) 
		random_seed = random_seed + int(key[i]);
		
	return random_seed;
}

vector<int> generate_random_key(int input_size)
{
    vector<int> random_key;
    for (int i = 0; i < input_size; ++i)
        random_key.push_back(rand() % MAX_RANDOM);

    return random_key;
}

text_t read_file_encryption(string input_path) 
{
    text_t input;
    
	ifstream file(input_path);
	string line;
	while (getline(file, line, GET_ENTER))
		for (char seek : line)
			input.push_back(seek);
	
	return input;
}

cipher_t read_file_decryption(string input_path) 
{
    cipher_t input;
    
	ifstream file(input_path);
	int seek;
	while (!file.eof()) 
	{
		file >> seek;
		input.push_back(seek);
	}
	
	return input;
}



cipher_t encryption_action(text_t input, vector<int> key)
{
    cipher_t cipher;
    for (int i = 0; i < input.size(); ++i)
    {
	    int cipher_block = int(input[i]) + key[i];
		cipher.push_back(cipher_block);
	}
	
	return cipher;
}

void encrypt_simple(string key, Path path, text_t input)
{
    cipher_t cipher;
    vector<int> generated_key = generate_key_for_simple_kind(key, input.size());
    cipher = encryption_action(input, generated_key);	

	create_output_file_enc(cipher, input.size(), path.output_file_path);
}

void encrypt_complicated(string key, Path path, text_t input) 
{
	cipher_t cipher;
	srand(create_random_seed(key));
	vector<int> random_key = generate_random_key(input.size());
	cipher = encryption_action(input, random_key);
    
	create_output_file_enc(cipher, input.size(), path.output_file_path);
}



text_t decryption_action(cipher_t input, vector<int> key)
{
    text_t text;
    for (int i = 0; i < input.size() - 1; ++i)
	{
	    char plain_char = char(input[i] - key[i]);
		text.push_back(plain_char);
	}
	
	return text;
}

void decrypt_simple(string key, Path path, cipher_t input)
{
    text_t text;
	vector<int> generated_key = generate_key_for_simple_kind(key, input.size());
	text = decryption_action(input, generated_key);

	create_output_file_dec(text, input.size(), path.output_file_path);
}

void decrypt_complicated(string key, Path path, cipher_t input) 
{
	text_t text;
	srand(create_random_seed(key));
	vector<int> random_key = generate_random_key(input.size());
	text = decryption_action(input, random_key);
	
	create_output_file_dec(text, input.size(), path.output_file_path);
}

void create_output_file_enc(cipher_t output, int input_size, string output_path)
{
	ofstream file(output_path);
	for (int i = 0; i < input_size; ++i)
		file << output[i] << endl;
}

void create_output_file_dec(text_t output, int input_size, string output_path)
{
	ofstream file(output_path);
	for (int i = 0; i < input_size - 1; ++i) 
		file << output[i];
}
