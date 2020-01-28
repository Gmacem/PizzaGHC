#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

using ll = long long;

class Solver {
public:
    ll num, sum, cur_sum;
    vector<ll> weights;
    vector<ll> output;

    void ReadData(){
        cin >> sum >> num;
        weights.resize(num);
        for (int i = 0; i < num; ++i) {
            cin >> weights[i];
        }
    }

    void Solve(){
        for (int i = num - 1; i >= 0; --i) {
            if (cur_sum + weights[i] <= sum) {
                output.push_back(i);
                cur_sum += weights[i];
            }
        }
    }

    void Print(){
        reverse(output.begin(), output.end());
        cout << output.size() << '\n';
        for (int i = 0; i < output.size(); ++i) {
            cout << output[i] << ' ';
        }
        cerr << "Diff: " << sum - cur_sum << '\n';
    }
};

void solve(){
    Solver solver;
    solver.ReadData();
    solver.Solve();
    solver.Print();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef D_PROB
    freopen("d_quite_big.in", "r", stdin);
#elif E_PROB
    freopen("e_quite_big.in", "r", stdin);
#endif
    solve();
}
