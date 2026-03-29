class MinStack{
public:
    MinStack(){}

    void push(int val){
        stack.push_back(val);
        if(sorted.find(val) != sorted.end()){
            sorted[val]++;
        }
        else{
            sorted[val] = 1;
        }
    }

    void pop(){
        int val = stack.back();
        sorted[val]--;
        if(sorted[val] == 0) sorted.erase(val);
        stack.pop_back();
    }

    int top(){
        return stack.back();
    }

    int getMin(){
        return sorted.begin() -> first;
    }


    private:

    vector<int> stack;
    map<int, int> sorted;
    
};
