#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
void check_add(string mot,map<string , int> *mapper);
void check_remove(string mot,map<string,int> *mapper);

int main()
{
    ifstream file("d_difficult.in.txt");
    ofstream sender("d_difficult.out.txt");
    string line1,mot;
    vector<string> greatter;
    map<string , int> ingredients;
    if(file.is_open())
    {
        cout << "is open\n";
        
        getline(file,line1);
        stringstream ssline1(line1);
        int n(0);
        ssline1 >> n;
        n*=2;
        while(n>0)
        {
            getline(file,line1);
            stringstream ssline1(line1);
            int val(0);
            ssline1 >> val;
            for(int i(0); i<val; i++){
                ssline1 >> mot;
                if(n%2==0)
                    check_add(mot,&ingredients);
                else
                    check_remove(mot,&ingredients);

            }
            n--;
        }

    }
    cout << ingredients.size()<< " ";
    map<string,int>::iterator it=ingredients.begin();

    while (it!=ingredients.end())   
    {
        if(it->second>0)
            greatter.push_back(it->first);

        it++;
    }
    
    sender << greatter.size()<< " ";
    for(int i(0); i<greatter.size(); i++){
       // cout << greatter[i] <<" ";
       sender << greatter[i] << " ";
    }
    cout << "\n";
    return 0;

}

void check_add(string mot,map<string , int> *mapper){
    if(mapper->find(mot)==mapper->end()){
        mapper->insert({mot,1});
    }else{
        (*mapper)[mot]++;
    }
}

void check_remove(string mot,map<string,int> *mapper){
     if(mapper->find(mot)==mapper->end()){
        mapper->insert({mot,-1});
    }else{
        (*mapper)[mot]--;
    }
}