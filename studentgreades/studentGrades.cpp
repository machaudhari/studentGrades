#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    ifstream fin;
    fin.open("grades.txt");
    ofstream fout;
    fout.open("out.txt");

    while(!fin.eof())
    {
        getline(fin, S);
        stringstream X(S);
        vector<string> strs;
        vector<int> arr;

        while(getline(X,T,' '))
        {
            strs.push_back(T);
        }

        string sname = "";
        bool flag = 0;
        double n = 0, sum = 0;
        for(string s: strs)
        {
            if(flag == 0 && s[0] <= '9' && s[0] >= '0')
            {
                flag = 1;
                n = stoi(s);
                continue;
            }
        
            else if(!isdigit(s[0]))
            {
                sname += s;
                sname += " ";
            }
            if(flag){
                sum += stoi(s);
                arr.push_back(stoi(s));
            }
        }
        double avg = sum/double(n);
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
        fout << "Student's name :"<<sname<<endl;
        fout << "Number of exam scores:"<<n<<endl;
        fout << "Exam scores:";
        for(int i = 0;i<arr.size();i++)
        {
            fout << arr[i]<<' ';
        }
        fout << endl;
        fout << "Average Exam score :"<<avg<<endl;
        fout << "Grade :"<< grade<<endl;
        fout<<endl;
        S = fin.get();
        if(S =="")
        {
            break;
        }
    };
    return 0;

}