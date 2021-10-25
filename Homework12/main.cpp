#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

void task12_06(){
    cout<<"Task 12.06"<<endl;
    std::string numbers;

    cout<<"Input numbers (1-1000), separated by comma: "<<endl;
    cin>>numbers;

    numbers = numbers.substr(0,numbers.length());

    int start_index = 0;
    int end_index = 1;

    int number_index = 0;
    double num_array[numbers.length()/2];

    while (end_index<numbers.length()){
        if (numbers[end_index]==','){
            num_array[number_index++] = 
                ::atof(numbers.substr(start_index,end_index-start_index).c_str());
            
            start_index = end_index+1;
        } else if (end_index==numbers.length()-1){
            num_array[number_index++] = 
                ::atof(numbers.substr(start_index,end_index-start_index+1).c_str());
        }
        end_index++;
    }

    int buffer_size = 8;
    for (int i=0; i<number_index; i++){
        stringstream num_log;
        char buffer1[buffer_size];
        char buffer2[buffer_size];

        snprintf(buffer1,buffer_size,"%5.3f",log(num_array[i]));
        snprintf(buffer2,buffer_size,"%5.3e",log(num_array[i]));

        num_log<<(long)log(num_array[i]);

        if (num_log.str().length()>buffer_size){
            printf("None\n\n");
            continue;
        }

        printf("log(%.3f) ~= %.3f\n",num_array[i], buffer1);
        printf("log(%.3f) ~= %.3e\n\n",num_array[i], buffer2);
    }
    
}

struct Date{
    int day;
    int month;
    int year;
};

Date date_parse(std::string &date_string){
    //(dd/mm/yyyy)
    Date output;
    output.day = ::atof(date_string.substr(1,2).c_str());
    output.month = ::atof(date_string.substr(4,2).c_str());
    output.year = ::atof(date_string.substr(7,4).c_str());
    return output;
}

const string date_toString(Date date){
    //(dd/mm/yyyy) length:12
    char buffer[12];
    stringstream datestr;
    datestr
        <<"("
        <<(date.day<10?"0":"")
        <<date.day<<'/'
        <<(date.month<10?"0":"")
        <<date.month
        <<'/'
        <<date.year
        <<')';
    return datestr.str();
}

void print_date(Date date){
    cout<<date_toString(date);
}


Date date_max(Date date1, Date date2){
    return (date1.year>date2.year || 
        (date1.year==date2.year && (date1.month>=date2.month || date1.day>=date2.day))
        )?date1:date2;
}

Date date_min(Date date1, Date date2){
    return (date1.year>date2.year || 
        (date1.year==date2.year && (date1.month>=date2.month || date1.day>=date2.day))
        )?date2:date1;
}

void task12_21(){
    //(dd/mm/yyyy),(dd/mm/yyyy),(dd/mm/yyyy),...

    cout<<"Task 12.21"<<endl;
    ofstream f;
    f.open("data.txt");
    if (!f) {
        cout<<"Error opening file"<<endl;
        f.close();
        return;
    }
    f<<"(12/11/1953),(23/10/2001),(06/08/2004),(16/11/2002),(17/01/1995),(22/07/2048)";
    f.close();

    ifstream f1;
    f1.open("data.txt", std::ifstream::in);

    f1.seekg (0, f1.end);
    int length = f1.tellg();
    f1.seekg (0, f1.beg);

    if (length<0){
        printf("File does not exist");
        f1.close();
        return;
    }

    char *buffer = new char [length];
    f1.read(buffer,length);

    f1.close();

    string data (buffer,length);
    
    Date* dates;

    int start_index=0;
    int end_index=1;

    //"(dd/mm/yyyy)," length = 13
    int dates_index = 0;
    dates = (Date*)calloc(data.length()/13,sizeof(Date));

    Date max_date = {-1,-1,-1};
    Date min_date = {-1,-1,-1};

    cout<<endl<<"Data read from file:"<<endl;
    while (end_index<data.length()){
        if (data[end_index]==',' || end_index==data.length()-1){
            string date_string = data.substr(start_index,end_index-start_index);
            Date date = date_parse(date_string);
            if (max_date.day<0 || min_date.day<0){
                max_date=date;
                min_date=date;
            } else {
                max_date=date_max(max_date,date);
                min_date=date_min(min_date,date);
            }

            print_date(date);
            cout<<endl;
            dates[dates_index++] = date;
            start_index = end_index+1;
        }
        end_index++;
    }

    cout<<endl
        <<"Min and max dates:"
        <<endl<<date_toString(max_date)
        <<endl<<date_toString(min_date);

    ofstream f3;
    f3.open("min_max_data.txt");
    if (!f3) {
        cout<<"Error opening file"<<endl;
        f3.close();
        return;
    }

    f3<<date_toString(max_date)<<','<<date_toString(min_date);
    f3.close();

    delete[] buffer;
    delete[] dates;
    
}

int main(){
    /*
    Вказівка 1. В кожному завданні має бути використане 
    форматування C++ за допомогою потоків виведення 
    (ostream) і оператора " << ".

    Домашнє завдання (для всіх):
    12.06

    Вказівка 2. В кожному завданні нижче (12.07-12.21) 
    мають бути використані файлові потоки C++ 
    (ifstream, ofstream або fstream) для текстових файлів.

    Індивідуальне завдання:
    11) Красовський Олександр 12.21
    */

    task12_06();
    task12_21();

    return 0;
}