//vector大小  如何调用方法访问元素  插入元素  删除元素

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


int main() {
    //大小
    int arr[]{ 1,2,3,4,5 };
    int i;
    vector<int> v1(arr, arr + 5);

    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }

    cout << endl;

    cout << "vi.size:" << v1.size() << endl;//v1.size()返回元素个数

    if (!v1.empty())
        cout << "v1 is not empty!" << endl;//v1.empty()判断容器是否为空 是1否0

    v1.resize(6);//v1.resize(num)用默认值填充容器 若num小于原来容器大小 则删除原来的多余的元素
    //若大于原来的大小  则用默认值 填充多余的
    cout << "v1.resize(6)后的元素:";

    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    v1.resize(8, 100);//v1.resize(num,elem) 与上一个不同的是 指定用elem填充多的元素

    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    //访问(调用方法 而非迭代器)
    vector<int> v2(arr, arr + 5);

    cout << "v2容器的第三个元素（[]访问）：";
    cout << v2[2] << endl;//[]访问 []在类模板vector中重载

    cout << "v2容器的第三个元素（at()访问）:";
    cout << v2.at(2) << endl;//与上一个的区别是 这里容器访问越界时会用异常提示  而上一个不会有 这在查找错误时帮助很大

    //插入  在末尾插入push_back() 和末尾删除pop_back() 和定点插入insert()
    vector<int> v3 = v2;

    v3.insert(v3.begin(), 0);//insert(pos,elem)在pos(指针，迭代器类型)位置插入一个 elem  返回新数据的位置
    cout << "在v3的第一个元素处 插入一个0：";

    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    v3.insert(v3.begin(), 3, 7);//insert(pos,n,elem)在pos位置插入n个elem元素  无返回值

    cout << "在v3的第一个元素出插入 3个7：";
    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;

    vector<int> vtemp(3, 9);

    cout << "v3的在第一个元素上插入3个9：";

    v3.insert(v3.begin(), vtemp.begin(), vtemp.end());//insert(pos,beg,end)在pos位置插入[beg,end)上的元素  无返回值
    for (i = 0; i < v3.size(); i++) {
          cout << v3[i] << " ";
    }
    cout << endl;

    v3.push_back(300);//在容器尾部插入300

    cout << "在v3的尾部插入300：";

    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;


    v3.pop_back();

    cout << "删除v3的最后一个元素：";

    for (i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;


    return 0;
}
