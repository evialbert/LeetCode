class Solution{
private:
    string time(int arr[]){
        string s="";
        int hour=0, minute=0;
        for(int i=3; i>=0; i--){
            hour = hour + (arr[i] * pow(2, 3-i));
        }
        if(hour >= 12){
            return "";
        }
        s = to_string(hour);
        s = s + ":";
        for(int i=9; i>=4; i--){
            minute = minute + (arr[i] * pow(2, 9-i));
        }
        if(minute >= 60){
            return "";
        }
        if(minute < 10){
            s = s + "0";
        }
        string minutes = to_string(minute);
        s = s + minutes;
        return s;
    }
    void backtrace(int turnedOn, vector<string> &ans, int arr[], int index, int point){
        if(index == turnedOn){
            string output = time(arr);
            if(output != ""){
                ans.push_back(output);
            }
            return;
        }
        for(int i=point; i <= (10-(turnedOn - index)); i++){
            arr[i]=1;
            backtrace(turnedOn, ans, arr, index+1, i+1);
            arr[i]=0;
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn){
        vector<string> ans;
        if(turnedOn==9 || turnedOn==10){
            return ans;
        }
        if(turnedOn == 0){
            ans.push_back("0:00");
            return ans;
        }
        int array[10]={0};
        backtrace(turnedOn, ans, array, 0, 0);
        return ans;
    }
};