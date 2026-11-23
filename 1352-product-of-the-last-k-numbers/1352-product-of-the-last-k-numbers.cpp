class ProductOfNumbers {
public:
    //Approach : Prefix Product with Zero-Reset

    //Time Complexity = O(1) per operation =>
    /* No loops or traversal needed.
    * Only uses temporary scalar variables.
    */

    //Space Complexity = O(n) =>
    /* `prod` array can store upto n elements in the worst case.
    */
    
    //prod[i] stores the cumulative product of elements from index 0 to i-1
    vector<int> prod;

    ProductOfNumbers() {
        prod = {1}; //Base Multiplier 1
    }

    void add(int num) {
        
        if(num == 0){//if number is zero then
            
            prod = {1};//reset the stream
        }

        else{
            prod.push_back(prod.back() * num);
        }
    }
    
    int getProduct(int k) {
        
        int n = prod.size() - 1;

        if(k > n){
            return 0;
        }

        return prod[n] / prod[n-k];     
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */