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
//			s.push_back(con[i]);//��ÿ���ַ���˳��װ�������ȥ
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
    //��ȡ���룬�����������ԭ������
    string s;
    list<char>l;
    list<char>::iterator it = l.begin();

    while (cin >> s) {
        int i = 0;
        while (i < s.size() + 1) {//string.size()������'\0'�� +1ȷ��'\0'Ҳ�ڴ���Χ��
            if (s[i] == '\0') {//������string�����е��ַ�����
                it = l.begin();
                while (it != l.end()) {
                    cout << *it;
                    it++;
                }
                cout << endl;
                //�������ʱ��list�����Ѿ��Ǽ��������� �����������
                l.clear();//������� ������һ�εĶ���һ��string�Ļ�ԭ
                it = l.begin();
            }
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
                l.insert(it, s[i]);
            //**��Ϊ�ε�����it����it++����Ȼ����һֱָ��l.begin()���𣿣�**//
            else if (s[i] == '>')it++;
            else if (s[i] == '<')it--;
            else if (s[i] == '[')it = l.begin();
            else if (s[i] == ']')it = l.end();

            i++;
        }
    }
    //����string �����ַ��� ������ӵ�list������ȥ  ������ ��� ����string��copy��list������ȥ �ٴ�������
    //����������  �ٷ��������е�ʱ������������solution



    /*Ϊ�ε�����it����it++����Ȼ����һֱָ��l.begin()����
        ����δ����У�`it` ��һ����������������ڽ�Ԫ�ز��뵽�б� `l` �С�
        ������ `l.insert(it, s[i])` ʱ��`it` ����Ҫ�ֶ����ӣ���Ϊ `insert` �������� `it` 
        ָ���λ�ò���Ԫ�أ����һ��Զ����� `it`��ʹ��ָ���²����Ԫ�ء�
        ��ˣ����������£�����Ҫ�ֶ����� `it`����Ϊ `insert` �������Զ����µ�������λ�á�*/


    /********* End *********/
}