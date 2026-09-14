#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

double eng[26] = {
    .08167,.01492,.02782,.04253,.12702,.02228,.02015,
    .06094,.06966,.00153,.00772,.04025,.02406,.06749,
    .07507,.01929,.00095,.05987,.06327,.09056,.02758,
    .00978,.02360,.00150,.01974,.00074
};

// 1. Remove spaces and special characters
string clean_ciphertext(const string& s) {
    string x;
    for(char c : s)
        if(isalpha(c))
            x += toupper(c);
    return x;
}

// 2. Find repeated 3-letter patterns
map<string, vector<int>> find_repeated_patterns(const string& s) {
    map<string, vector<int>> p;

    for(int i = 0; i + 3 <= (int)s.size(); i++)
        p[s.substr(i,3)].push_back(i);

    for(auto it = p.begin(); it != p.end(); ) {
        if(it->second.size() < 2)
            it = p.erase(it);
        else
            ++it;
    }

    return p;
}

// 3. Find distances between repeated patterns
vector<int> calculate_distances(
    const map<string, vector<int>>& p) {

    vector<int> d;

    for(auto x : p) {
        for(int i = 1; i < (int)x.second.size(); i++)
            d.push_back(x.second[i] - x.second[i-1]);
    }

    return d;
}

// 4. Find factors of distances
map<int,int> find_factors(const vector<int>& d) {
    map<int,int> f;

    for(int x : d)
        for(int i = 2; i <= 20; i++)
            if(x % i == 0)
                f[i]++;

    return f;
}

// 5. Index of Coincidence
double calculate_ic(const string& s) {
    int n = s.size();
    if(n < 2) return 0;

    int f[26] = {};

    for(char c : s)
        f[c-'A']++;

    int sum = 0;

    for(int i = 0; i < 26; i++)
        sum += f[i] * (f[i]-1);

    return (double)sum / (n*(n-1));
}

// 6. Kasiski analysis
int kasiski_analysis(const string& s) {

    auto patterns = find_repeated_patterns(s);
    auto distances = calculate_distances(patterns);
    auto factors = find_factors(distances);

    cout << "\n=== KASISKI ANALYSIS ===\n";

    cout << "\nRepeated Patterns:\n";
    for(auto x : patterns) {
        cout << x.first << " : ";
        for(int p : x.second)
            cout << p << " ";
        cout << endl;
    }

    cout << "\nDistances:\n";
    for(int x : distances)
        cout << x << " ";

    cout << "\n\nFactor Counts:\n";
    for(auto x : factors)
        cout << x.first << " -> " << x.second << endl;

    // Display IC for possible Kasiski lengths
    cout << "\n=== INDEX OF COINCIDENCE ===\n";
    cout << "Length\tAverage IC\n";

    int best = 1;
    double bestScore = 0;

    for(auto x : factors) {

        int k = x.first;

        vector<string> groups(k);

        for(int i = 0; i < (int)s.size(); i++)
            groups[i % k] += s[i];

        double avg = 0;

        for(string g : groups)
            avg += calculate_ic(g);

        avg /= k;

        cout << k << "\t"
             << fixed << setprecision(4)
             << avg << endl;

        // English IC is approximately 0.066
        if(avg > bestScore && avg > 0.05) {
            bestScore = avg;
            best = k;
        }
    }

    // If IC doesn't give a strong result,
    // use the most frequent Kasiski factor.
    if(best == 1 && !factors.empty()) {
        for(auto x : factors) {
            if(x.second > factors[best])
                best = x.first;
        }
    }

    return best;
}

// 7. Split ciphertext into groups
vector<string> split_into_groups(
    const string& s, int keyLen) {

    vector<string> groups(keyLen);

    for(int i = 0; i < (int)s.size(); i++)
        groups[i % keyLen] += s[i];

    return groups;
}

// 8. Frequency analysis of every group
vector<vector<int>> frequency_analysis(
    const vector<string>& groups) {

    vector<vector<int>> all;

    cout << "\n=== FREQUENCY ANALYSIS ===\n";

    for(int g = 0; g < (int)groups.size(); g++) {

        int f[26] = {};

        for(char c : groups[g])
            f[c-'A']++;

        vector<int> v(f, f+26);
        all.push_back(v);

        cout << "\nGroup " << g+1 << ":\n";

        for(int i = 0; i < 26; i++)
            cout << char('A'+i) << ":" << f[i] << " ";

        cout << endl;
    }

    return all;
}

// 9. Find Caesar shift using chi-square
int find_shift(const string& s) {

    int f[26] = {};

    for(char c : s)
        f[c-'A']++;

    int n = s.size();
    int best = 0;
    double minChi = 1e100;

    for(int shift = 0; shift < 26; shift++) {

        double chi = 0;

        for(int i = 0; i < 26; i++) {

            int observed = f[(i + shift) % 26];
            double expected = n * eng[i];

            if(expected > 0)
                chi += (observed-expected) *
                       (observed-expected) / expected;
        }

        if(chi < minChi) {
            minChi = chi;
            best = shift;
        }
    }

    return best;
}

// 10. Recover key
string find_key(const vector<string>& groups) {

    string key;

    cout << "\n=== KEY RECOVERY ===\n";

    for(int i = 0; i < (int)groups.size(); i++) {

        int shift = find_shift(groups[i]);

        key += char('A' + shift);

        cout << "Group " << i+1
             << " Shift = " << shift
             << " Key = " << char('A'+shift)
             << endl;
    }

    return key;
}

// 11. Decrypt
string vigenere_decrypt(
    const string& s, const string& key) {

    string p;

    for(int i = 0; i < (int)s.size(); i++) {

        int c = s[i]-'A';
        int k = key[i % key.size()]-'A';

        p += char('A' + (c-k+26)%26);
    }

    return p;
}

// 12. Encrypt
string vigenere_encrypt(
    const string& s, const string& key) {

    string c;

    for(int i = 0; i < (int)s.size(); i++) {

        int p = s[i]-'A';
        int k = key[i % key.size()]-'A';

        c += char('A' + (p+k)%26);
    }

    return c;
}

// 13. Verify
bool verify(const string& ciphertext,
            const string& key) {

    string plaintext =
        vigenere_decrypt(ciphertext, key);

    string encrypted =
        vigenere_encrypt(plaintext, key);

    return encrypted == ciphertext;
}


int main() {

    // Read ciphertext
    ifstream file("outputs/ciphertext.txt");

    if(!file) {
        cout << "Error: Cannot open ciphertext.txt\n";
        return 1;
    }

    string raw(
        (istreambuf_iterator<char>(file)),
        istreambuf_iterator<char>());

    file.close();

    // 1. Clean ciphertext
    string ciphertext = clean_ciphertext(raw);

    cout << "========================================\n";
    cout << " VIGENERE CRYPTANALYSIS\n";
    cout << "========================================\n";

    cout << "Ciphertext length: "
         << ciphertext.size() << endl;

    // 2-5. Kasiski + IC
    int keyLen = kasiski_analysis(ciphertext);

    cout << "\nEstimated Key Length: "
         << keyLen << endl;

    // 6. Split into groups
    vector<string> groups =
        split_into_groups(ciphertext, keyLen);

    // 7. Frequency analysis
    frequency_analysis(groups);

    // 8. Find key
    string key = find_key(groups);

    cout << "\nRecovered Key: "
         << key << endl;

    // 9. Decrypt
    string plaintext =
        vigenere_decrypt(ciphertext, key);

    cout << "\n=== RECOVERED PLAINTEXT ===\n";
    cout << plaintext << endl;

    // Save plaintext
    ofstream out("outputs/recovered_plaintext.txt");

    out << plaintext;
    out.close();

    // 10. Verify
    cout << "\n=== VERIFICATION ===\n";

    if(verify(ciphertext, key))
        cout << "Re-encryption successful: YES\n";
    else
        cout << "Re-encryption successful: NO\n";

    return 0;
}