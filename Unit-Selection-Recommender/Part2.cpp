#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define GRADES "grades.csv"
#define COURSES "courses.csv"
#define COMMA ','
#define DASH '-'
#define COLON ':'
#define PERIOD '.'
#define A_GPA 17
#define A_MAX 24
#define B_MAX 20
#define INVALID -1
#define VALID 0

using namespace std;

struct schedule{
    string day;
    double start_time;
    double end_time;
};
typedef vector<schedule> scheduleTable;
typedef struct schedule scheduleInfo;

typedef vector<int> numsList;
typedef vector<double> gradesTable;

struct course{
    int id;
    string name;
    int units;
    scheduleTable all_schedule;
    numsList prerequisties;
};
typedef vector<course> courseTable;
typedef struct course courseInfo;

string digital_time_to_float(string word)
{
    for(int i = 0 ; i < word.size() ; i++)
    {
        if(word[i] == COLON)
            word[i] = PERIOD;
    }
    return word;
}

void write_each_schedule_inf(int i, string word, scheduleInfo& each_schedule)
{
    if(i == 1)
        each_schedule.day = word;
            
    if(i == 2)
        each_schedule.start_time = stof(digital_time_to_float(word));
                
    if(i == 3)
        each_schedule.end_time = stof(digital_time_to_float(word));
}

scheduleTable write_all_schedules_inf(string date_time_course)
{
    scheduleTable all_schedule;
    scheduleInfo each_schedule;

    string word,item;
    stringstream date_time(date_time_course);
    for(int j = 0 ; getline(date_time,item,'/') ; j++)
    {
        all_schedule.push_back(schedule());
        stringstream ss_item(item);
        
        for(int i = 1 ; getline(ss_item,word,DASH) ; i++)
        {
            write_each_schedule_inf(i,word,each_schedule);
            all_schedule[j] = each_schedule;
        }
    }
    return all_schedule;
}

scheduleTable create_all_schedule(string date_time_course)
{
    scheduleTable all_schedule = write_all_schedules_inf(date_time_course);
    return all_schedule;
}

numsList create_all_prerequisties(string word)
{
    numsList prerequisties;
    stringstream ss_word(word);
    for(int i = 1 ; getline(ss_word,word,DASH) ; i++)
        prerequisties.push_back(stoi(word));
            
    return prerequisties;
}

void write_each_course_inf(int i,string word,courseInfo& each_course)
{
    if(i == 1)
        each_course.id = stoi(word);
        
    if(i == 2)
        each_course.name = word;
        
    if(i == 3)
        each_course.units = stoi(word);
        
    if(i == 4)
        each_course.all_schedule = create_all_schedule(word);
        
    if(i == 5)
        each_course.prerequisties = create_all_prerequisties(word);
}

courseTable write_all_courses_inf(ifstream& input_file)
{
    courseTable course_table;
    courseInfo each_course;

    string line, word;
    getline(input_file,line);
    for(int j = 0 ; getline(input_file,line) ; j++)
    {
        course_table.push_back(course());
        stringstream ss_line(line);
        
        for(int i = 1 ; getline(ss_line,word,COMMA) ; i++)
        {
            write_each_course_inf(i,word,each_course);
            course_table[j] = each_course;
        }
    }
    
    return course_table;
}

courseTable read_course_info()
{
    ifstream input_file(COURSES);
    return write_all_courses_inf(input_file);
}

gradesTable read_grades()
{
    ifstream grade_file(GRADES);
    gradesTable grade_table;
    string word,line;
    
    getline(grade_file,line);
    while(getline(grade_file,line))
    {
        stringstream ss_line(line);
        while(getline(ss_line,word,COMMA))
            grade_table.push_back(stof(word));
    }
    return grade_table;
}

gradesTable write_passed_courses()
{
    gradesTable passed_courses = read_grades();
    for(int j = 1 ; j <  passed_courses.size() ; j = j + 2)
    {
        if(passed_courses[j] < 10)
            {
                passed_courses[j] = INVALID;
                passed_courses[j - 1] = INVALID;
            }
    }
    return passed_courses;
}

void check_prerequisties(courseTable& course_table, gradesTable passed_courses)
{
    for(int j = 0; j < course_table.size() ; j++)
    {
        for(int i = 0 ; i < passed_courses.size() ; i = i + 2)
        {
            for(int k = 0 ; k < (course_table[j].prerequisties).size() ; k++)
            {
                if(passed_courses[i] == course_table[j].prerequisties[k])
                    course_table[j].prerequisties[k] = VALID;
            }
        }
    }
}

void check_if_passed_already(courseTable& course_table, gradesTable passed_courses)
{
    for(int j = 0; j < course_table.size() ; j++)
    {
        for(int i = 0 ; i < passed_courses.size() ; i = i + 2)
        {
            if(passed_courses[i] == course_table[j].id)
                course_table[j].prerequisties[0] = INVALID;
        }
    }
}

bool sort_by_units(const course& first, const course& second) 
{
    if(first.units == second.units)
        return first.name < second.name;

    return first.units > second.units; 
}

bool sort_by_name(const course& first, const course& second) { return first.name < second.name; }

courseTable create_takable_courses(courseTable course_table)
{
    gradesTable passed_courses = write_passed_courses();
    
    check_prerequisties(course_table,passed_courses);
    check_if_passed_already(course_table,passed_courses);
    
    courseTable takable_courses;
    
    for(int j = 0; j < course_table.size() ; j++)
    {
        int is_takable = VALID;
        for(int k = 0 ; k < (course_table[j].prerequisties).size() ; k++)
        {
            if(course_table[j].prerequisties[k] != VALID)
                is_takable = INVALID;
        }
        if(is_takable != INVALID)
            takable_courses.push_back(course_table[j]);
    }
    
    return takable_courses;
}

bool course_not_calculated(courseTable course_table,int k) { return course_table[k].units != INVALID; }

double calculate_GPA(courseTable course_table)
{
    gradesTable grade_table = read_grades();
    double sum_grades = 0;
    int sum_units = 0;
    double GPA;
    
    for(int j = grade_table.size() - 1 ; j > 0 ; j = j - 2)
    {
        for(int k = 0 ; k < course_table.size() ; k++)
        {
            if(course_not_calculated(course_table,k))
            {
                if(grade_table[j - 1] == course_table[k].id)
                {
                    sum_units = sum_units + course_table[k].units;
                    sum_grades = sum_grades + grade_table[j] * course_table[k].units;
                    course_table[k].units = INVALID;
                    break;
                }
            }   
        }
    }
    
    GPA = sum_grades / sum_units;
    return GPA;
}

bool has_time_interference(courseTable takable_courses,
                            int i,int j,int k,int l)
{
    return
    !(takable_courses[i].all_schedule[k].start_time >=
    takable_courses[j].all_schedule[l].end_time ||
    takable_courses[i].all_schedule[k].end_time <=
    takable_courses[j].all_schedule[l].start_time);
}

bool has_day_interference(courseTable takable_courses,
                        int i,int j,int k,int l)
{
    return takable_courses[i].all_schedule[k].day ==
           takable_courses[j].all_schedule[l].day;
}

courseTable check_for_interference(courseTable takable_courses,int down_course,int before)
{
    for(int k = 0 ; k < takable_courses[down_course].all_schedule.size() ; k++)
    {
        for(int l = 0 ; l < takable_courses[before].all_schedule.size() ; l++)
        {
            if(has_day_interference(takable_courses,down_course,before,k,l))
            {
                if(has_time_interference(takable_courses,down_course,before,k,l))
                    takable_courses[down_course].id = INVALID;
            }
        }
    }
    
    return takable_courses;
}

courseTable choose_units(courseTable takable_courses)
{
    sort(takable_courses.begin(), takable_courses.end(), sort_by_units);
    
    for(int down_course = takable_courses.size() - 1 ; down_course >= 0 ; down_course--)
    {
        for(int before = down_course - 1 ; before >= 0 ; before--)
            takable_courses = check_for_interference(takable_courses,down_course,before);
    }
    
    return takable_courses;
}

int calculate_max_units_possible(courseTable course_table)
{
    int max_units = A_MAX;
    if(calculate_GPA(course_table) < A_GPA)
        max_units = B_MAX;
    
    return max_units;
}

void generate_output(courseTable chosen_courses, courseTable course_table)
{
    int max_units = calculate_max_units_possible(course_table);
    int current_units = 0;
    
    sort(chosen_courses.begin(), chosen_courses.end(), sort_by_name);
    for(int i = 0 ; i < chosen_courses.size(); i++)
    {
        if(chosen_courses[i].id != INVALID)
        {
            current_units = current_units + chosen_courses[i].units;
            if(current_units <= max_units)
                cout << chosen_courses[i].id << endl;
                
            else
                break;
        }
    }
}

int main()
{
    courseTable course_table = read_course_info();
    courseTable takable_courses = create_takable_courses(course_table);
    courseTable chosen_courses = choose_units(takable_courses);
    generate_output(chosen_courses,course_table);
}