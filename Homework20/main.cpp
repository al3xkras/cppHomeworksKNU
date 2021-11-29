#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <fstream>

void task20_12(const std::string& name, std::vector<long> &v){
    assert(v.size()%2==0);

    std::set<long> s1;
    std::set<long> s2;

    for (int i=0; i<v.size()/2; i++){
        s1.insert(v[i]);
        s2.insert(v[v.size()-i-1]);
    }



    std::set<long> s2_diff_s1;
    std::set_difference(s2.begin(), s2.end(), s1.begin(),s1.end(),std::inserter(s2_diff_s1, s2_diff_s1.end()));

    std::ofstream f(name,std::ios_base::trunc | std::ios_base::out);

    assert(f.is_open());
    for (long x: s2_diff_s1){
        std::cout<<x<<std::endl;
        f<<x<<std::endl;
    }

    f.close();
}

void task20_15(const std::string &NameT, const std::string &NameS){
    std::map<char, int> m;

    std::ifstream f(NameT,std::ios_base::in);

    assert(f.is_open());
    for (char c; f.get(c);){
        if (m.count(c)){
            m[c]++;
            continue;
        }
        m[c] = 1;
    }

    f.close();

    std::ofstream f2(NameS,std::ios_base::trunc | std::ios_base::out);

    assert(f2.is_open());
    for(std::pair<char,int> p: m){
        std::cout<<p.first<<' '<<p.second<<std::endl;
        f2<<p.first<<' '<<p.second<<std::endl;
    }

    f2.close();
}

int main() {
    //11 Красовський Олександр 20.12, 20.15

    //task20_12
    std::vector<long> v = {3,1,2,5,3,4};
    std::cout<<std::endl<<std::endl<<"Task 20.12"<<std::endl;
    task20_12("numbers.txt",v);

    //task20_15
    std::ofstream f("characters.txt",std::ios_base::trunc | std::ios_base::out);
    f<<"aaaaabbcDDeFbBdaabbCcZZZehzzz";
    f.close();

    std::cout<<std::endl<<std::endl<<"Task 20.15"<<std::endl;
    task20_15("characters.txt","character_count.txt");
    return 0;
}
