#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

void task13_13(){
    cout<<"Task 13.13"<<endl;

    string _str;
    string substr;
    string word;
    

    cout<<"Input some string: ";
    cin.get();
    getline(cin,_str);

    cout<<endl<<"Input substring: ";
    cin.get();
    getline(cin,substr);

    cout<<endl<<"Input word: ";
    cin.get();
    getline(cin,word);

    if (word.find(" ")!=string::npos){
        cout<<"This is not a word."<<endl;
        return;
    }

    string tmp = _str.substr();
    int substr_count = 0;
    int found_at = 0;
    while ((found_at=tmp.find(substr))!=string::npos){
        tmp = tmp.substr(found_at+substr.length());
        substr_count++;
    }

    
    tmp = _str.substr();
    int word_count = 0;
    int word_found_at = 0;
    while ((word_found_at=tmp.find(word))!=string::npos){
        if ((word_found_at==0 && tmp[word.length()]==' ') ||
           (word_found_at==tmp.length()-word.length() && tmp[word_found_at-2]==' ') || 
           (tmp[word_found_at-2]==' ' && tmp[word_found_at+word.length()]==' ')){
            word_count++;
        }

        tmp = tmp.substr(word_found_at+word.length());
    }

    cout<<"Substring occurs "<<substr_count<<" times"<<endl
        <<"Word occurs "<<word_count<<" times"<<endl;
}

void task13_20(){
    cout<<endl<<"Task 13.20"<<endl;

    string nums = "one two three four five four nine three fjfnekrfk eight -1 minus one seven";


    string numbers[9][2] = {
        {"one","1"},
        {"two","2"},
        {"three","3"},
        {"four","4"},
        {"five","5"},
        {"six","6"},
        {"seven","7"},
        {"eight","8"},
        {"nine","9"}
    };

    cout<<"Initial string: "<<endl<<"  "<<nums<<endl;
    for (int i=0; i<9; i++){
        nums = ReplaceAll(nums, numbers[i][0], numbers[i][1]);
    }
    cout<<"Edited string: "<<endl<<"  "<<nums<<endl;
}

void task13_18(){
    cout<<"Task 13.18"<<endl;
    
    std::string pattern("[a-zA-Z]+ings");
    std::regex rx(pattern);

    std::string _str("mornings ings word   timings    word  evenings");

    cout<<"String: "<<_str<<endl;

    auto words_begin = std::sregex_iterator(_str.begin(), _str.end(), rx);
    auto words_end = std::sregex_iterator();

    cout<<"Words: "<<endl;
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;                                                 
        std::string match_str = match.str(); 
        std::cout << "  " << match_str << endl;
    }
}

void task13_19(){
    cout<<"Task 13.19"<<endl;
    string latin;
    cout<<"Input latin letters string: ";
    cin>>latin;

    char latin_letters[latin.length()];
    strcpy(latin_letters, latin.c_str());

    for (int i=0; i<latin.length();i++){
        if (('a'<=latin_letters[i] & 'z'>=latin_letters[i])){
            latin_letters[i] = 'a'+((latin_letters[i]-'a'+1))%('z'-'a'+1);
        } else if ('A'<=latin_letters[i] & 'Z'>=latin_letters[i]){
            latin_letters[i] = 'A'+((latin_letters[i]-'A'+1))%('Z'-'A'+1);
        }
    }

    cout<<latin_letters<<endl;
}

int main(){
    //11 Красовський Олександр 13.18, 13.19
    task13_18();
    task13_19();
    task13_13();
    task13_20();
    return 0;
}