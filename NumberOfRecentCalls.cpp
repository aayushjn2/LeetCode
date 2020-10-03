class RecentCounter {
private:
    int counter;
    vector<int> v;
    int start;
public:
    RecentCounter() {
        this->start = 0;
        this->counter = 0;
    }
    
    int ping(int t) {
        this->counter++;
        this->v.push_back(t);
        while( t - this->v[start] > 3000){
            this->start++;
            this->counter--;
        }
        return this->counter;
    }
};