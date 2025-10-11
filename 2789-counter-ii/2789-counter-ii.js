/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    
    let temp = init;

    return {

        increment: function() {
            temp = temp + 1;
            return temp;
        },

        decrement: function(){
            temp = temp - 1;
            return temp;
        },

        reset: function(){
            temp = init;
            return temp;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */