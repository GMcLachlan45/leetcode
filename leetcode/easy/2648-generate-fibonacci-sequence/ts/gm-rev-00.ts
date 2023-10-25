// Runtime 55ms
// Memory 44.6MB
function* fibGenerator(): Generator<number, any, number> {
    yield 0;
    yield 1;
        
    let n_0 : number = 0;
    let n_1 : number = 1;

    while(true) {
        let temp : number = n_0 + n_1;
        n_0 = n_1;
        n_1 = temp;
        yield temp;
    };
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
