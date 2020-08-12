#include <bits/stdc++.h>
using namespace std;
priority_queue <int> lower;// max_heap
priority_queue <int, vector<int>, greater<int>> higher;// min heap

void add_element(int element){
    if((lower.size() == 0) || element < lower.top()){
        lower.push(element);
    }
    else{
        higher.push(element);
    }
}

void fix(){
    int l = lower.size();
    int r = higher.size();
    int diff = abs( l - r);
    if(diff>=2){
        if(lower.size() > higher.size()){
            higher.push(lower.top());
            lower.pop();
        }
        else{
            lower.push(higher.top());
            higher.pop();
        }
    }
}

double getMedian(){
    if(lower.size() == higher.size()){
        return ((double)lower.top()+higher.top())/2;
    }
    else if(lower.size() > higher.size()){
        return lower.top();
    }
    else{
        return higher.top();
    }
}

vector<double> runningMedian(vector<int> a) {
    vector<double> ans;
    for(int i=0;i<a.size();i++){
        add_element(a[i]);
        fix();
        ans.push_back(getMedian());
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
