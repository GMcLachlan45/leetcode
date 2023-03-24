var calculateTax = function(brackets, income) {var t=0,c=0,p=0;for(var i=0;i<brackets.length;i++){c=brackets[i][0];t+=(Math.min(c,income)-p)*(brackets[i][1]/100);p=c;if(income<p){break;}}return t;};
