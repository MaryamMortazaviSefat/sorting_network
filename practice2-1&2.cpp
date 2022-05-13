#include <iostream>
#include <vector>
#include <string>
using namespace std;

void read_network(vector<string> & network,int row);
void read_numbers(vector<int>& numbers ,int row);
bool is_valid_network(vector<string> network, int num_of_stages);
void process(vector<string> network,vector<int>& numbers,int num_of_stages);
void generate_output(vector<int>numbers) ;



int main() {
    int row;
    int column;
    vector<string> network;
    vector<int> numbers;

    cin >> row >> column;

    read_network( network,row);
    read_numbers( numbers,row);
    if(is_valid_network(network,column)){
        process(network,numbers,column);
        generate_output(numbers);
    }
    return 0;
}


void read_network(vector<string> &network,int row) {
    for (int i = 0; i < row; ++i) {
        string last_network;
        cin >> last_network;
        network.push_back(last_network);
    }}

void read_numbers(vector<int>&numbers ,int row){
    for (int i = 0; i < row; i++) {
        int last_num;
        cin >> last_num;
        numbers.push_back(last_num);
    }
}

bool is_valid_network(vector<string> network,int num_of_stages) {
    for(int i=0;i<network.size();i++)
    {
        if(network[i].size()!=num_of_stages)
        {
            cout<<"the size of strings are not equal with colunm(num of stages) !"<<"\n";
            return false;
        }
    }


    for (int j = 0; j < num_of_stages; j++)
    {
        for (int i = 0; i < network.size();i++)
        {
            if(network[i][j] != '-'){
                if (network[i][j] < 'a' || network[i][j] > 'z' )
                {
                    cout <<"Invalid Network\n";
                    return false;
                }
                    int count = 1;
                    for (int k = i + 1; k < network.size(); k++)
                    {
                         count = 1;
                        if (network[i][j] == network[k][j])
                        {
                            count++;
                            i=k;
                            break;
                        }
                    }
                        if (count != 2)
                        {
                            cout << "Invalid Network\n";
                            return false;
                        }

                  }
        }
    }
    return true;
}


void process(vector<string>network,vector<int>&numbers,int num_of_stages){
    for (int j = 0; j < num_of_stages; j++)
    {
        for (int i = 0; i < network.size()-1 ; i++)
        {
            if(network[i][j] != '-')
            {
                    for (int k = i + 1; k < network.size(); k++)
                    {
                        if (network[i][j] == network[k][j])
                        {
                            if (numbers[i] > numbers[k])
                            {
                                int temp = numbers[i];
                                numbers[i] = numbers[k];
                                numbers[k] = temp;
                            }
                            i=k;
                            break;
                        }
                    }
             }
        }
    }
}

void generate_output(vector<int>numbers) {
        bool sort=true;  //function sorted
        for (int i = 0; i < numbers.size() - 1 && sort; i++)
         {
            if (numbers[i] > numbers[i+1])
            {
                cout << "Not sorted\n";
                sort=false;
            }
         }

        if(sort)
        {cout<<"sorted\n";}
}

