

var deepEquality = (obj1,obj2)=>{

    // checkIsProperObject(obj1);
    // checkIsProperObject(obj2);
    if (typeof(obj1) == typeof(obj2)){
        if (typeof(obj1)=='undefined') return true;
        else if (typeof(obj1)=='number'){
            return (obj1 === obj2) ? true : false;
        }
        else if (typeof(obj1)=='string'){
            return (obj1 === obj2) ? true : false;
        }
        else if (typeof(obj1)== 'object'){
            if (obj1 ==='null'&& obj2==='null'){
                return true;
            }
            else{
                if(obj1 instanceof Array){
                    // con,sole.log(obj1 === obj2)
                    obj1.sort();
                    obj2.sort();


                }
                let a1 = Object.keys(obj1).map(function(k)
                {return[k,obj1[k]];
                });
                let a2 = Object.keys(obj2).map(function(k)
                {return[k,obj2[k]];
                });
                

                if(a1.length === a2.length){
                    a1.forEach( (value, key, map)=>{
                        if(key in a2){
                            if(a1[key] !== a2[key]) return false 
                        }
                        else return false
                        return true
                    } )
                }
                else return false

        }

        }
    }
};
// console.log([1,2,3] instanceof Array)
console.log(deepEquality({a:4,b:5}, {b:5, a:4}))