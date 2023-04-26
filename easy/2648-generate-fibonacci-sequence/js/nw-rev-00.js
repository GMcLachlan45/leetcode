//62ms
//42MB
var fibGenerator = function*() {
    var x1 = 0;
    var x2 = 1;

    while(true){
        yield x1;
        [x1,x2] = [x2, x1 + x2];
    }
};
