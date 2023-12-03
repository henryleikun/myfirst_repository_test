//#include <iostream>
//#include <string>
//#include <list>
//
//using namespace std;
//
//int main() {
//
//	list<char>  s;
//	//list<char>  s_t;
//	int times=0;
//	list<char>::iterator it;
//	list<char>::iterator it1;
//
//	string con;
//
//	while (getline(cin, con)) {
//		for (int i = 0; i < con.size(); i++)
//			s.push_back(con[i]);//把每个字符按顺序装到结点中去
//		for (it = s.begin(); it != s.end();) {
//			while (*it == '<') {
//				times++;
//				it = s.erase(it);
//				if (*it == '<')
//					continue;
//				if (*it == '[') {
//					it = s.erase(it);
//					s.push_front(*it);
//					it = s.erase(it);
//				}
//
//				if (*it == ']') {
//					it = s.erase(it);
//				}
//			}
//			it++;
//		}
//		
//			it1 = it;
//
//			for (int i = 0; i < times||it != s.begin(); it--, i++) {
//
//			}
//
//			s.insert(it, *it1);
//			
//			for (it = s.begin(); it != s.end(); it++)
//				cout << *it;
//			cout << endl;
//	}
//
//	return 0;
//}


#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    /********* Begin *********/
    //读取输入，解析并输出复原后的输出
    string s;
    list<char>l;
    list<char>::iterator it = l.begin();

    while (cin >> s) {
        int i = 0;
        while (i < s.size() + 1) {//string.size()不包含'\0'的 +1确保'\0'也在处理范围内
            if (s[i] == '\0') {//遍历完string中所有的字符串后
                it = l.begin();
                while (it != l.end()) {
                    cout << *it;
                    it++;
                }
                cout << endl;
                //处理到这的时候list容器已经是键盘输入了 进行输出就行
                l.clear();//清空容器 进行下一次的对下一个string的还原
                it = l.begin();
            }
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
                l.insert(it, s[i]);
            //**！为何迭代器it不用it++，不然不就一直指向l.begin()了吗？！**//
            else if (s[i] == '>')it++;
            else if (s[i] == '<')it--;
            else if (s[i] == '[')it = l.begin();
            else if (s[i] == ']')it = l.end();

            i++;
        }
    }
    //输入string 处理字符串 慢慢添加到list容器中去  而不是 你的 先让string中copy到list容器中去 再处理容器
    //根本处理不了  再放入容器中的时候就做处理才是solution



    /*为何迭代器it不用it++，不然不就一直指向l.begin()了吗？
        在这段代码中，`it` 是一个插入迭代器，用于将元素插入到列表 `l` 中。
        当调用 `l.insert(it, s[i])` 时，`it` 不需要手动增加，因为 `insert` 方法会在 `it` 
        指向的位置插入元素，并且会自动更新 `it`，使其指向新插入的元素。
        因此，在这个情况下，不需要手动增加 `it`，因为 `insert` 方法会自动更新迭代器的位置。*/


    /********* End *********/
}