class MinStack{
public:
    MinStack(){}

    void push(int val){
        if(stack.size()){
            stack.push_back({val,min(stack.back().second,val)});
        }
        else{
            stack.push_back({val,val});
        }
    }

    void pop(){
        stack.pop_back();
    }

    int top(){
        return stack.back().first;
    }

    int getMin(){
        return stack.back().second;
    }


    private:

    vector<pair<int,int>> stack;
    
};