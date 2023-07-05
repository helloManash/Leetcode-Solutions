/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let count=init
// inline JS
   const increment=() =>++count;
   const decrement =()=>--count;
   const reset=()=>{count=init 
   return count;}

   return {
       increment,decrement,reset
   }
};