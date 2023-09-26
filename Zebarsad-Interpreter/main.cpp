
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#define MINIMUM_STEPS "Minimum Steps: "
#define DOLLAR '$'
#define SPACE ' '
#define PLUS '+'
#define SUB '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define EQUAL '='
#define ZERO "0"
#define NINE "9"
#define QMARK '?'
#define EXCLAMATION '!'
#define PLUS_ "+"
#define SUB_ "-"
#define MULTIPLY_ "*"
#define DIVIDE_ "/"
#define EMPTY ""

using namespace std;

void get_input(stringstream& input);

typedef vector<string> code_t;
typedef vector<int> inputs_t;
typedef vector<vector<string> > base_t;


class Variable
{
public:
	Variable(string name_);
	string get_name();
	int get_value();
	void set_value(int value_);
private:
	string name;
	int value;
};

Variable::Variable(string name_)
{
	name = name_;
	value = 0;
}
void Variable::set_value(int value_)
{
	value = value_;
}

string Variable::get_name()
{
	return name;
}

int Variable::get_value()
{
	return value;
}

typedef vector<Variable*> variables_t;

class SameName
{
public:
	SameName(string name_) : name(name_) {}
	bool operator()(Variable* variable);
private:
	string name;
};

bool SameName::operator()(Variable* variable)
{
	return variable->get_name() == name;
}

class Interpreter
{
public:
	Interpreter(stringstream& input_);
	void order_input_line_by_line();
	void process_code_line_by_line();
	void process_each_line(string line);
	void declare_variable(string name);
	void print_output(string expression);
	void make_assignment(string line);
	void process_expression_for_assignment(Variable* variable, 
		 string expression);

	bool check_for_operators(string expression);
	int apply_operators_effect(string expression);
	string find_first_variable_from_right(string expression);
	vector<string> organize_expression(string expression);
	int get_number_value(string name);
	int apply_adding_effect(int var_1, string var_name);
	int apply_subtraction_effect(int var_1, string var_name);
	int apply_multiplication_effect(int var_1, string var_name);
	int apply_division_effect(int var_1, string var_name);

	void create_code_base(string line);
	vector<string> create_base_each_line(string line);
	int find_connections();
	void calculate_minimum_steps();

private:
	stringstream user_input;
	code_t code;
	inputs_t zebarsad_inputs;

	variables_t variables;
	base_t code_base;
};

Interpreter::Interpreter(stringstream& input_)
{
	user_input << input_.str();
}

void Interpreter::order_input_line_by_line()
{
	string line, word;
	while(getline(user_input, line))
	{
		stringstream ss_line(line);
		string each_line = EMPTY;

		if(line[0] != DOLLAR)
			while(getline(ss_line, word, SPACE))
				each_line += word;

		else
		{
			getline(ss_line, word, SPACE);
			while(getline(ss_line, word, SPACE))
				zebarsad_inputs.push_back(stoi(word));

			continue;
		}
		code.push_back(each_line);
	}
}

void Interpreter::process_code_line_by_line()
{
	for(auto line : code)
	{
		process_each_line(line);
		create_code_base(line);
	}
	calculate_minimum_steps();
}

void Interpreter::calculate_minimum_steps()
{
	int decreased_steps = find_connections();
	int min_steps = code.size() - decreased_steps;
	if(min_steps <= 0)
		min_steps = code.size() - 2;

	cout << MINIMUM_STEPS << min_steps << endl;
}

int Interpreter::find_connections()
{
	int counter= 0;
	for(int i = code_base.size() - 1; i > 0; i--)
		for(int j = i - 1; j > 0; j--)
		{
			int flag = 0;
			for(int w = 0; w < code_base[j].size(); w++)
				if(code_base[i][0] == code_base[j][w])
					flag = 1;

			if(flag == 0)
			{
				int flag2 = 0;
				for(int k = 0; k < code_base[i].size(); ++k)
					if(code_base[j][0] == code_base[i][k])
						flag2 = 1;

				if(flag2 == 0)
				{
					counter++;
					break;
				}
				else
					break;
			}
			else
				break;
		}
	return counter;
}

vector<string> Interpreter::create_base_each_line(string line)
{
	vector<string> base;
	string variable;
	for(auto ch = line.rbegin(); ch != line.rend(); ++ch)
	{
		if(*ch == PLUS || *ch == SUB || *ch == MULTIPLY || *ch == DIVIDE || *ch == EQUAL)
		{
			if(variable >= ZERO && variable <= NINE)
			{
				variable = EMPTY;
				continue;
			}
			
			base.push_back(variable);
			variable = EMPTY;
			continue;
		}
		variable.insert(0, 1, *ch);
	}
	base.push_back(variable);
	reverse(base.begin(), base.end());
	return base;
}

void Interpreter::process_each_line(string line)
{
	if(line[0] == QMARK)
		declare_variable(line.substr(1));

	else if(line[0] == EXCLAMATION)
		print_output(line.substr(1));

	else
		make_assignment(line);
}

void Interpreter::declare_variable(string name)
{
	Variable* variable = new Variable(name);

	auto value = zebarsad_inputs.begin();
	variable->set_value(*value);
	zebarsad_inputs.erase(value);

	variables.push_back(variable);
}


void Interpreter::print_output(string expression)
{
	auto found_var = find_if(variables.begin(), variables.end(), SameName(expression));

	if(found_var != variables.end())
		cout << (*found_var)->get_value() << endl;

	else
		cout << apply_operators_effect(expression) << endl;
}

void Interpreter::make_assignment(string line)
{
	int pos = line.find(EQUAL);
	string var_name = line.substr(0, pos);
	string expression = line.substr(pos + 1);

	auto found_var = find_if(variables.begin(), variables.end(), SameName(var_name));
	if(found_var != variables.end())
		process_expression_for_assignment(*found_var, expression);

	else
	{
		Variable* variable = new Variable(var_name);
		variables.push_back(variable);

		process_expression_for_assignment(variable, expression);
	}
}

bool Interpreter::check_for_operators(string expression)
{
	for(char& ch : expression)
		if(ch == PLUS || ch == SUB || ch == MULTIPLY || ch == DIVIDE)
			return true;
}

void Interpreter::process_expression_for_assignment(Variable* variable, 
	 string expression)
{
	if(check_for_operators(expression))
	{
		variable->set_value(apply_operators_effect(expression));
		return;
	}

	auto found_var = find_if(variables.begin(), variables.end(), SameName(expression));
	if(found_var != variables.end())
	{
		int right_assignment_value = (*found_var)->get_value();
		variable->set_value(right_assignment_value);
	}
	else if(expression >= ZERO && expression <= NINE)
		variable->set_value(stoi(expression));

	else
	{
		Variable* var = new Variable(expression);
		variables.push_back(var);
		
		variable->set_value(0);	
	}
}

int Interpreter::apply_operators_effect(string expression)
{
	vector<string> organized_expression = organize_expression(expression);
	int var_1 = get_number_value(organized_expression[organized_expression.size()-1]);

	for(int i = organized_expression.size() - 1; i > 0; i--)
	{
		if(organized_expression[i] == PLUS_)
			var_1 = apply_adding_effect(var_1, organized_expression[i-1]);

		if(organized_expression[i] == SUB_)
			var_1 = apply_subtraction_effect(var_1, organized_expression[i-1]);

		if(organized_expression[i] == MULTIPLY_)
			var_1 = apply_multiplication_effect(var_1, organized_expression[i-1]);

		if(organized_expression[i] == DIVIDE_)
			var_1 = apply_division_effect(var_1, organized_expression[i-1]);
	}
	return var_1;
}

int Interpreter::get_number_value(string name)
{
	if(name >= ZERO && name <= NINE)
		return stoi(name);

	auto found_var = find_if(variables.begin(), variables.end(), SameName(name));
	if(found_var == variables.end())
	{
		Variable* variable = new Variable(name);
		variables.push_back(variable);
		return 0;
	}

	return (*found_var)->get_value();

}
int Interpreter::apply_adding_effect(int var_1, string var_name)
{
	int var_2 = get_number_value(var_name);
	return var_1 + var_2;
}

int Interpreter::apply_subtraction_effect(int var_1, string var_name)
{
	int var_2 = get_number_value(var_name);
	return var_2 - var_1;
}
int Interpreter::apply_multiplication_effect(int var_1, string var_name)
{
	int var_2 = get_number_value(var_name);
	return var_1 * var_2;
}

int Interpreter::apply_division_effect(int var_1, string var_name)
{
	int var_2 = get_number_value(var_name);
	return var_2 / var_1;
}


vector<string> Interpreter::organize_expression(string expression)
{
	string variable;
	vector<string> organized_expression;
	for(auto ch = expression.rbegin(); ch != expression.rend(); ++ch)
	{
		if(*ch == PLUS || *ch == SUB || *ch == MULTIPLY || *ch == DIVIDE)
		{
			organized_expression.insert(organized_expression.begin(), variable);
			variable = EMPTY;
			string s(1, *ch);
			organized_expression.insert(organized_expression.begin(), s);

			continue;
		}
		variable.insert(0, 1, *ch);
	}
	organized_expression.insert(organized_expression.begin(), variable);

	return organized_expression;
}

void Interpreter::create_code_base(string line)
{
	if(line[0] == EXCLAMATION)
		code_base.push_back(create_base_each_line(line.insert(1, 1, PLUS)));
	else if(line[0] == QMARK)
		code_base.push_back(create_base_each_line(line.substr(1)));

	else
		code_base.push_back(create_base_each_line(line));
}


void get_input(stringstream& input)
{
	string line;
	while(getline(cin, line))
		input << line << endl;
}

int main()
{
    stringstream input;
    get_input(input);
    Interpreter interpreter(input);
    interpreter.order_input_line_by_line();
    interpreter.process_code_line_by_line();

}