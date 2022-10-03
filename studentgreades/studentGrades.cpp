#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream read;
    read.open("grades.txt");
    ofstream write;
    write.open("out.txt");
    string S, Q;

    while(read.eof()==0)
    {
        getline(read, S);
        stringstream P(S);
        vector<string> strs;
        vector<int> arr;

        while(getline(P,Q,' '))
        strs.push_back(Q);

        string std = "";
        bool flag = false;
        double N = 0, sum = 0;
        for(string s: strs){
            if(s[0] <= '9' && s[0] >= '0'&& flag == false )
            {
                flag = true;
                N = stoi(s);
                continue;
            }
        
            else if(!isdigit(s[0]))
            {
                std += s;
                std += " ";
            }
            if(flag){
                sum += stoi(s);
                arr.push_back(stoi(s));
            }
        }
        double avg = sum/double(N);
        string grade;
        if(avg<=100 & avg>95){
            grade = "A";
        }
        else if(avg<=95 & avg>91.67){
                grade = "A-";
        }
        else if(avg<=91.67 & avg>88.3){
                grade = "B+";
        }
        else if(avg<=88.3 & avg>85){
                grade = "B";
        }
        else if(avg<=85 & avg>81.67){
                grade = "B-";
        }
        else if(avg<=81.67 & avg>78.33){
                grade = "C+";
        }
        else if(avg<=78.33 & avg>75){
                grade = "C";
        }
        else if(avg<=75 & avg>71.67){
                grade = "C-";
        }
        else if(avg<=71.67 & avg>68.33){
                grade = "D+";
        }
        else if(avg<=68.33 & avg>65){
                grade = "D";
        }
        else if(avg<=65 & avg>61.67){
                grade = "D-";
        }
        else{
                grade = "F";
        }
        if(N){
        write << "Student's Name :"<<std<<endl;
        write << "Number Of Exam Scores:"<<N<<endl;
        write << "Exam Scores:";
        for(int i = 0;i<arr.size();i++)
        {
            write << arr[i]<<' ';
        }
        write << endl;
        write << "Average Exam Score :"<<avg<<endl;
        write << "Grade :"<< grade<<endl;
        write<<endl;
        }
        // S = read.get();
        // if(S =="")
        // {
        //     break;
        // }
    }
    return 0;

}
