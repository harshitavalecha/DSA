class Solution {
public:
stack<int>st;
    int calPoints(vector<string>& operations) {
        for(int i=0; i<  operations.size();i++){
            if( operations[i] =="C"){
                 st.pop();
            }
            else if(operations[i]=="D"){
                st.push(2*st.top());
            }
            else if(operations[i]=="+"){
                int a=st.top();
                st.pop();
                int b= st.top();
                st.push(a);
                st.push(a+b);
            }
            else{
            st.push(stoi(operations[i]));
            }

        }
        int sum=0;
        while(!st.empty()){
            sum=sum+st.top();
            st.pop();
        }
        return sum;
    }
};