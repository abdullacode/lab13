#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>


using namespace std;

double print(map<double, double>p4){
    for (auto item = p4.begin(); item != p4.end(); item++)
        cout << item->first << ' ' << item->second << endl;
}
void displayPairs(const unordered_map<string, int>& myMap) {
    cout << "Pairs in the map:\n";
    for (const auto& pair : myMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}
void show(const set<int>& s) {
    cout << "Elements in sorted order:";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}
void show(const unordered_set<int>& s) {
    cout << "Elements:";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}
void show(const multiset<int>& s) {
    cout << "Elements:";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}
bool isSymmetric(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return false;
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    for (int i = 0; i < n; ++i) {
        if (sorted_nums[i] % 10 != sorted_nums[n - 1 - i] % 10) {
            return false;
        }
    }
    return true;
}
void displayQueue(queue<int> q) {
    cout << "Elements in the queue:";
    while (!q.empty()) {
        cout << " " << q.front();
        q.pop();
    }
    cout << endl;
}
void clearQueue(queue<int>& q) {
    while (!q.empty()) {
        q.pop();
    }
}

int main(){
    cout<< "PROBLEM 1\n"<<endl;
    map<int, int> m;
    m.insert({1, 1});
    m.insert({2, 4});
    m.insert({3, 9});
    m.insert({4, 16});
    m.insert({5, 25});
    cout << "Elements in the map:" << endl;
    for (const auto& pair : m) {
        cout << "Square of  " << pair.first << "is " << pair.second << endl;
    }


    cout<< "PROBLEM 2\n"<<endl;
    map<int, string> competitionResults;
    vector<pair<int, string>> students = {{74, "Mike"}, {76, "Elena"}, {93, "David"},
                                          {70, "George"}, {89, "Indira"}};
    sort(students.begin(), students.end(), greater<pair<int, string>>());
    for (size_t i = 0; i < students.size(); ++i) {
        competitionResults[i + 1] = students[i].second;
    }
    for (const auto& result : competitionResults) {
        cout << result.first << " place is " << result.second << ".\n";
    }

    cout<< "PROBLEM 3\n"<<endl;
    map<char,int> mp{};
    for(int i=0; i<26;i++){
        mp[(char)('A'+i)]=i+1;
    }
    char inp{};
    cin>>inp;
    if(mp[inp]){
        cout<<mp[inp]<<endl;
    }else{
        cout<<"Not found!"<< endl;
    }


    cout<< "PROBLEM 4\n"<<endl;
    map<double,double> p4{pair(4, 7.5), pair(25,6.01), pair (-9,3.2), pair(12, 5.16)};
    print(p4);
    p4.insert(pair(3, 3.75));
    print(p4);
    p4.insert(pair(-10, 4.3));
    print(p4);
    auto it=p4.find(12);
    if(it!=p4.end()){
        cout<<it-> second<<endl;
    }
    p4.erase(it);
    for (auto item:p4){
        cout<<item.first <<" , "<< item.second<<endl;
    }
    p4[-9]=4.44;
    for(auto item: p4){
        cout<<item.first<< " , " <<item.second<<endl;
    }


    cout<< "PROBLEM 5\n"<<endl;
    unordered_map<string, int> Map = {{"Earth", 3}, {"Mercury", 1}, {"Venus", 2}};
    displayPairs(Map);
    Map.insert(Map.begin(), make_pair("Mars", 4));
    cout << "\nMap after inserting ('Mars', 4) into the beginning:\n";
    displayPairs(Map);
    auto it1 = Map.begin();
    advance(it1, 2);
    Map.emplace_hint(it1, "Saturn", 6);
    Map.emplace_hint(it1, "Neptune", 8);
    cout << "\nMap after inserting ('Saturn', 6) and ('Neptune', 8) into position 3:\n" ;
    displayPairs(Map);
    cout << "\nSize of the map: " << Map.size() << endl;
    Map.erase("Venus");
    cout << "\nMap after deleting element with key 'Venus':\n";
    displayPairs(Map);


    cout<< "PROBLEM 6\n"<<endl;
    multimap<int, int> myMultiMap = {{100, 3}, {150, 4}, {100, 90}};
    cout << "Number of keys equal to 100: " << myMultiMap.count(100) << endl;
    myMultiMap.insert({200, 32});
    myMultiMap.insert({100, -12});
    myMultiMap.insert({90, 45});
    auto it2 = myMultiMap.upper_bound(100);
    cout << "Keys and values at upper bound of key 100:\n";
    for (int i = 0; i < 2 && it2 != myMultiMap.end(); ++i, ++it2) {
        cout << "Key: " << it2->first << ", Value: " << it2->second << endl;
    }
    auto pairToDelete = myMultiMap.find(100);
    if (pairToDelete != myMultiMap.end()) {
        myMultiMap.erase(pairToDelete);
    }
    cout << "\nResulting map after deleting elements with key 100:\n";
    for (const auto& pair : myMultiMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }


    cout<< "PROBLEM 7\n"<<endl;
    int numUsers;
    cout << "Enter the number of users who want to register: ";
    cin >> numUsers;
    unordered_map<string, int> registeredUsers;
    for (int i = 0; i < numUsers; ++i) {
        string name;
        cin >> name;
        if (registeredUsers.find(name) == registeredUsers.end()) {
            registeredUsers[name] = 1;
            cout << "OK " << name << endl;
        } else {
            int count = registeredUsers[name]++;
            cout << name << count << endl;
        }
    }


    cout<< "PROBLEM 8\n"<<endl;
    int n;
    cin>>n;
    int arr[n];
    map <int, int> occurances;
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    for(int i=0; i<n; i++){
        if (!occurances.count(arr[i])){
            occurances.insert(pair(arr[i], 1));
        }else{
            occurances[arr[i]]++;
        }
    }
    bool good=true;
    for (int i=0; i<n;i++) {
        if (occurances[arr[i]] != arr[i]) {
            good = false;
            break;
        }
    }
    if(good){
        cout<<"Good sequence"<<endl;
    }else{
        cout<<"Not good sequence"<<endl;
    }

    cout<< "PROBLEM 9\n"<<endl;
    set<int> s;
    s.insert(5);
    s.insert(39);
    s.insert(10);
    s.insert(64);
    s.insert(82);
    s.insert(35);
    s.insert(10);
    s.insert(54);
    show(s);


    cout<< "PROBLEM 10\n"<<endl;
    unordered_set<int> s1;
    s1.insert(5);
    s1.insert(39);
    s1.insert(10);
    s1.insert(64);
    s1.insert(82);
    s1.insert(35);
    s1.insert(10);
    s1.insert(54);
    show(s1);


    cout<< "PROBLEM 11\n"<<endl;
    multiset<int> s2;
    s2.insert(5);
    s2.insert(39);
    s2.insert(10);
    s2.insert(64);
    s2.insert(82);
    s2.insert(35);
    s2.insert(10);
    s2.insert(54);
    cout << "Original elements:\n";
    show(s2);
    auto it_start = s2.find(10);
    auto it_end = s2.find(54);
    if (it_start != s2.end() && it_end != s2.end()) {
        s2.erase(it_start, it_end);
    }
    cout << "\nElements after removing elements from 10 to before 54:\n";
    show(s2);


    cout<< "PROBLEM 12\n"<<endl;
    srand(time(nullptr));
    multiset<int> mySet;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = rand() % 10 + 11;
        mySet.insert(randomNumber);
    }
    cout << "Multiset: ";
    for (const auto& num : mySet) {
        cout << num << " ";
    }
    cout << endl;
    int inputNum;
    cout << "Enter a number from 11 to 20: ";
    cin >> inputNum;
    auto it3 = mySet.find(inputNum);
    if (it3 != mySet.end()) {
        cout << "YES" << endl;
    } else {
        cout << "Number not found in multiset" << endl;
    }


    cout<< "PROBLEM 13\n"<<endl;
    int size;
    cout << "Enter the size of the sets: ";
    cin >> size;
    set<int> set1, set2;
    cout << "Enter elements of set 1: ";
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        set1.insert(num);
    }
    cout << "Enter elements of set 2: ";
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        set2.insert(num);
    }
    set<int> unionSet, intersectionSet, differenceSet;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(unionSet,
                                                                           unionSet.begin()));set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     inserter(intersectionSet, intersectionSet.begin()));
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   inserter(differenceSet, differenceSet.begin()));
    cout << "Union=";
    for (int num : unionSet) {
        cout << num << " ";
    }
    cout << "Intersection=";
    for (int num : intersectionSet) {
        cout << num << " ";
    }
    cout << "Difference=";
    for (int num : differenceSet) {
        cout << num << " ";
    }
    cout << endl;


    cout<< "PROBLEM 14\n"<<endl;
    int n1;
    cout << "Enter the size of the vector: ";
    cin >> n1;
    vector<int> nums(n1);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums[i];
    }
    set<int> uniqueNums(nums.begin(), nums.end());
    nums.assign(uniqueNums.begin(), uniqueNums.end());
    cout << "Resulting vector:";
    for (int num : nums) {
        cout << " " << num;
    }
    cout << endl;
    cout << "Size of the resulting vector: " << nums.size() << endl;


    cout<< "PROBLEM 15\n"<<endl;
    string S;
    int q;
    cout << "Enter the string S: ";
    cin >> S;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--) {
        int i, j, k;
        cout << "Enter query (i, j, k): ";
        cin >> i >> j >> k;
        i--;
        j--;
        string sub = S.substr(i, j - i + 1);
        if (k == 0) {
            sort(sub.begin(), sub.end(), greater<char>());
        } else {
            sort(sub.begin(), sub.end());
        }
        S.replace(i, j - i + 1, sub);
    }
    cout << "Final string after applying the queries: " << S << endl;


    cout<< "PROBLEM 16\n"<<endl;
    int n2;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n2;
    vector<int> nums2(n);
    cout << "Enter the sequence: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    if (isSymmetric(nums2)) {
        cout << "Symmetric ";
    } else {
        cout << "Not symmetric ";
    }
    sort(nums2.begin(), nums2.end());
    cout << "Sorted sequence:";
    for (int num2 : nums2) {
        cout << " " << num2;
    }
    cout << endl;


    cout<< "PROBLEM 17\n"<<endl;
    queue<int> q1;
    cout << "Enter a series of integers (-1 to end): ";
    int num;
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        q1.push(num);
    }
    cout << "Size of the queue: " << q1.size() << endl;
    if (!q1.empty()) {
        cout << "Front element: " << q1.front() << endl;
        cout << "Back element: " << q1.back() << endl;
    } else {
        cout << "Queue is empty." << endl;
    }
    displayQueue(q1);
    clearQueue(q1);
    cout << "Size of the queue after clearing: " << q1.size() << endl;

    cout<< "PROBLEM 18\n"<<endl;
    stack<int> myStack;
    myStack.push(43);
    myStack.push(90);
    myStack.push(100);
    myStack.push(30);
    myStack.push(28);
    myStack.push(1);
    myStack.push(34);
    cout << "Size of the stack: " << myStack.size() << endl;
    if (!myStack.empty()) {
        cout << "Value at top: " << myStack.top() << endl;
    } else {
        cout << "Stack is empty." << endl;
    }
    while (!myStack.empty() && myStack.top() != 30) {
        myStack.pop();
    }
    cout << "Size of the stack after deleting required elements: " << myStack.size()<< endl;
    return 0;
}