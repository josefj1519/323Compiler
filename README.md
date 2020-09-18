# Lexx & Yacc Compiler
by: \
Josef Jankowski \
Jason Otter \
Ian Nyguen 

The C++ prgoram will parse the source text and remove comments, spaces, and new lines.  \
Result in the interim file:
```
  PROGRAM aba13;
  VAR
  ab5, cb, be, eb : INTEGER;
  BEGIN
  ab5 = 5;
  cb = 10;
  PRINT('ab5=', ab5);
  eb = cb + ab5;
  PRINT( eb );
  be = 2 * ab5 + eb;
  PRINT( be );
  END.
  ```
  Then running the lex yacc using the interim file, will output a C++ program. \
  Result:
  ```
  #include <iostream>
Using namespace std;
int main()
{
int ab5, cb, be, eb;
ab5 = 5
cout << ”ab5=” << ab5;
eb = cb + ab5;
cout << eb;
be = 2 * ab5 + eb;
cout << be;
return 0;
}
```
