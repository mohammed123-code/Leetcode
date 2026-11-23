class ProductOfNumbers {
public:
    vector<int>pref;

    ProductOfNumbers() {}

    void add(int num) {
        if(num == 0)
        {
            pref.clear();
            return;
        }
        int i = pref.size();
        if(i >= 1)
            pref.push_back(pref[i-1]*num);
        else
            pref.push_back(num);
    }  
    int getProduct(int k) 
    {
        int i = pref.size();
        if(i < k)
            return 0;
        if(i == k)
            return pref[i-1];
        return pref[i-1] / pref[i - k - 1];
    }
};