## TODO
-[ ] 1
export a=b
export a
를할 때, a=b로 유지되어야 함

-[ ] 2
export a="asda s dasdas ads"
export
를 할 때,  a="asda s dasdas ads"로 들어가야 함

-[x] 3
워드확장 후에 빈 문자열 혹은 null은 없애고 command를 당겨야한다.

-[x] 4
워드확장 후에 빈 문자열과 null은 다르게 처리되어야 한다.
빈 문자열은 커멘드로 취급해야하고
null은 존재하지 않는 것으로 취급해서 arguments를 당겨야한다.