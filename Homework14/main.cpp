#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void task14_07(){
    cout<<endl<<"Task 14.07"<<endl<<endl;
    ofstream _students("students.txt", std::ostream::out);

    _students<<
            "StudentName1 StudentSurname1 group1 5 5"<<endl<<
            "StudentName1 StudentSurname1 group2 1.5 2 1.3 2 3 2 2 2 2 2 2"<<endl<<
            "StudentName1 StudentSurname1 group1 5 2"<<endl<<
            "StudentName1 StudentSurname1 group2 5 4 4 5 4.5 4 5 4 5 5"<<endl<<
            "StudentName1 StudentSurname1 group2 5 5 5 4 4 3 4 3 5 3 3 4 3 4 2 4.3"<<endl;
    _students.close();

    string group;
    int grades_count = 0;
    double group_sum = 0;
    double group_mean;

    cout<<"Input group: ";
    cin>>group;

    ifstream students("students.txt", std::istream::in);
    string current_line;
    while(std::getline(students,current_line)){
        string _group;
        int spaces_found = 0;
        int space_i = 0;
        while ((space_i=current_line.find(' '))!=string::npos){
            if (spaces_found==2){
                _group = current_line.substr(0,space_i);
                current_line = current_line.substr(space_i+1);
                break;
            }
            spaces_found++;
            current_line = current_line.substr(space_i+1);
        }

        if (!(_group==group)){
            continue;
        }

        cout<<current_line<<endl;

        stringstream sstr(current_line);
        double grade;
        
        while (sstr>>grade){
            group_sum += grade;
            grades_count++;
        }
    }

    group_mean = group_sum/grades_count;

    cout<<endl<<"Mean grade of group \""<<group<<"\": "<<group_mean<<endl;

    students.close();
}

void task14_20(){
    cout<<endl<<"Task 14.20"<<endl<<endl;
    ofstream f("task14_20_data.txt", std::ostream::out);

    f<<
      "col1"<<endl<<
      "col2"<<endl<<
      "col3"<<endl<<
      "col4"<<endl<<
      "col5"<<endl<<
      "col6"<<endl<<
      "col7"<<endl<<
      "col8"<<endl<<
      "col9"<<endl<<
      "col10"<<endl;
    f.close();

    int N1,N2;

    cout<<"Input N1>0: ";
    cin>>N1;

    cout<<"Input N2>0: ";
    cin>>N2;

    if (N1<0 || N2<0){
        return;
    }

    int tmp = N1;

    N1 = N1>N2?N2:N1;
    N2 = tmp>N2?tmp:N2;

    ofstream f2("task14_20.txt", std::ostream::out);

    ifstream f1("task14_20_data.txt", std::istream::in);

    int current_line_index = 0;
    string current_line;
    while(std::getline(f1,current_line)){
        current_line_index++;
        if (current_line_index>N1 && current_line_index<N2){
            f2<<endl;
            continue;
        }
        f2<<current_line<<endl;
    }

    if (current_line_index<N1-1 || current_line_index<N2-1){
        cout<<"Impossible!"<<endl;
        f2.close();
        f2.open("task14_20.txt", std::ostream::out);
        f2<<"Impossible!";
    }


    f1.close();
    f2.close();
}

int main(){
    //11 Красовський Олександр 14.07, 14.20
    task14_07();
    task14_20();
    return 0;
}