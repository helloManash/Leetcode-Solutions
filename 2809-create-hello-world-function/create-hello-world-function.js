/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const st = "Hello World";
    return function(...args) {
        return "Hello World";
    }

};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */