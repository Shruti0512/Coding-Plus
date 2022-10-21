#include <vector>
using namespace std;

/**
 * A binary indexed tree that can efficiently update elements and calculate prefix sums in a table of numbers.
 */
class FenwickTree {
   private:
    vector<int> fenwickTree;

   public:
    FenwickTree(int n) {
        fenwickTree.assign(n + 1, 0);
    }
    int rangeSumQuery(int b) {
        int sum = 0;
        for (; b; b -= (b & (-b))) sum += fenwickTree[b];
        return sum;
    }
    int rangeSumQuery(int a, int b) {
        return rangeSumQuery(b) - (a == 1 ? 0 : rangeSumQuery(a - 1));
    }
    void updateValue(int k, int v) {
        for (; k < fenwickTree.size(); k += (k & (-k))) {
            fenwickTree[k] += v;
        }
    }
};

int main() {
    
}