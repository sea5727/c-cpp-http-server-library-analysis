# crow

[reference](https://www.slideshare.net/JaeseungHa/ndc2015-c11-crow)

### Routing : CROW_ROUTE
어떤 요청에 어떤 응답을 줄지 
```cpp
CROW_ROUTE(app, "/")
CROW_ROUTE(app, "/post/all")
CROW_ROUTE(app, "/post/<int>")
CROW_ROUTE(app, "/near/<double>/<double>")
```

<int>
<uint>
<double>
<str>
<path>
