#include<iostream>
#include <map>
#include <vector>

//struct
struct ntah{
   std::string subject;
   std::string name;
   int uts;
   int uas;
};

int main(){
    //Size of data
    int n;
    std::cout<<"Banyak data: ";std::cin>>n;
    ntah temp[n];
    
    //memorize index
    std::map<std::string, std::vector<int>> index = {};
    
    //input
    for(int i=0;n>i;i++){
        std::cin>>temp[i].name>>temp[i].subject>>temp[i].uts>>temp[i].uas;
        index[temp[i].subject].push_back(i);
    }

    for (auto const& i : index) {
            std::cout << "Nilai "<<i.first << std::endl;
            for (auto const& j : i.second) {
                std::cout <<"Nama: "<<temp[j].name << std::endl;
                std::cout <<"UTS: "<< temp[j].uts << std::endl;
                std::cout <<"UAS: "<< temp[j].uas << std::endl;
                float avg =1.0*(temp[j].uts+temp[j].uas)/2;
                std::cout <<"AVG: "<< avg << std::endl;
            }
            std::cout<<"---------------\n";
        }
	
    return 0;
}