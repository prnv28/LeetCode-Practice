/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//  int32_t intercept = [] {
//     std::string str{};
//     std::string str2{};
//     std::priority_queue<int16_t, std::vector<int16_t>, std::greater<int16_t>>
//         pq{};

//     {
//         std::ofstream out{"user.out"};
//         while (std::getline(std::cin, str) and std::getline(std::cin, str2)) {
//             {
//                 std::stringstream stream;
//                 std::replace(str.begin(), str.end(), ',', ' ');
//                 stream << std::string{str.begin() + 1, str.end() - 1};
//                 int16_t val{};
//                 while (!stream.eof()) {
//                     stream >> str;
//                     if (std::stringstream(str) >> val)
//                         pq.emplace(val);
//                 }
//             }
//             {
//                 std::stringstream stream;
//                 std::replace(str2.begin(), str2.end(), ',', ' ');
//                 stream << std::string{str2.begin() + 1, str2.end() - 1};
//                 int16_t val{};
//                 while (!stream.eof()) {
//                     stream >> str2;
//                     if (std::stringstream(str2) >> val)
//                         pq.emplace(val);
//                 }
//             }

//             out << '[';
//             if (!pq.empty()) {
//                 out << pq.top();
//                 pq.pop();
//             }
//             for (; !pq.empty(); pq.pop())
//                 out << ',' << pq.top();
//             out << ']' << '\n';
//         }

//         std::cout << "str" << str << std::endl;
//         std::cout << "str2 " << str2 << std::endl;
//     }

//     exit(0);

//     return 0;
// }();
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        list2->next = mergeTwoLists(list2->next,list1);
        return list2;
    }
    
};