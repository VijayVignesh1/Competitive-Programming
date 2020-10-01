#include <iostream>
#include<vector>
using namespace std;

class RecentCounter {
public:
    vector<int> request;
    RecentCounter() {
        request.clear();
    }
    
    int ping(int t) {
        int count=0;
        request.push_back(t);
        for(int i=request.size()-1;i>=0;i--){
            if(request[i]>=t-3000)
                count+=1;
            else
                break;
        }
        return count;
    }
};

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}
int main()
{
    /**
    * Your RecentCounter object will be instantiated and called as such:
    */
    RecentCounter* obj = new RecentCounter();
    int param_1 = obj->ping(1);
    int param_2 = obj->ping(3003); // Last Call
    cout<<"Requests List:";
    print(obj->request);
    cout<<endl;
    cout<<"Number of Recent Calls: "<<param_2; // Param of last call is the count of recent calls
   
   return 0;
}
