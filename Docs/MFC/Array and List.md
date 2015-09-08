**CUIntArray Usage**
```cpp
CUIntArray array;

array.SetSize(5);
array.InsertAt(3, 77);
for(int i=0; i<array.GetSize(); i++)
	wcout<<"["<<i<<"]"<<array[i]<<endl;
wcout<<"=========="<<endl;

array.RemoveAt(2);
for(int i=0; i<array.GetSize(); i++)
	wcout<<"["<<i<<"]"<<array[i]<<endl;
wcout<<endl;
```

**CArray Usage**
```cpp
CArray<Point3D, const Point3D&> array;
array.SetSize(5);
for(int i=0; i<array.GetSize(); i++){
	Point3D pt(i, i*10, i*100);
	array[i] = pt;
}
for(int i=0; i<array.GetSize(); i++){
	Point3D pt = array[i];
	wcout<<pt.x<<", "<<pt.y<<", "<<pt.z<<endl;
}
```

**CStringList Usage**
```cpp
_tsetlocale(LC_ALL, _T(""));
TCHAR *szFruits[] = {
	_T("사과\n"), _T("딸기\n"), _T("포도\n"), _T("오렌지\n"), _T("자두\n")
};
CStringList list;
for(int i=0; i<5; i++)
	list.AddHead(szFruits[i]);
CString str;
POSITION pos = list.GetTailPosition();
for(int i=0; i<5; i++){
	_tprintf(list.GetPrev(pos));
}
```

**NOTICE**
리스트 범위를 초과하게 되면, 런타임 에러가 발생한다.
POSITION pos = list.GetTailPos();
list.GetNext(pos);  //리스트 꼬리에서 다음 요소에 접근했기 때문에 런타임 에러 발생.
