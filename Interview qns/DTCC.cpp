1 SQL query and 2 DSA qns.

SQL Question:
// Find prices that are more than 50% of the average price of that product.
// Return:
// product.id
// product.name
// price (only those > 50% of average)
// avg_price (rounded to 2 decimals)

// Sort by avg_price descending.
  
SELECT 
    p.id AS product_id,
    p.name,
    ph.price,
    ROUND(AVG(ph.price) OVER (PARTITION BY p.id), 2) AS avg_price
FROM 
    products p
JOIN 
    product_history ph 
    ON p.id = ph.product_id
WHERE 
    ph.price > 0.5 * (
        SELECT AVG(ph2.price)
        FROM product_history ph2
        WHERE ph2.product_id = p.id
    )
ORDER BY 
    avg_price DESC;

DSA question:
1. Given 2 arrays one with timestamps and another with a string and a int K. Return true or false based if the resource is accessed in last k time if accessed then put false else true
   Using hashmap and check if the string exist or not if exist check if the last timstamps - current timestamp is greater K if true then add true in the array else false
   as well if not exist in the map then add a false

2. Transform 2 arrays to equal elements and size if can return the length else return -1
    Try add up the sum of 2 arrays and check if it same or not if not same then we can't make it equal so return -1
    if same then use a 2-pointer approach.
    Ex: arr1=[3,2,3,7,10] arr2=[5,10,5,5] we can tranform the array into [5(3+2),10(3+7),10] [5,10,10] so length would 3 that is the ans
    int sum1=0,sum2=0;
    int i=0,j=0,count=0;
    while(i<n && j<m){
       if(sum1<sum2){
         sum1+=arr1;
        i++;
       }else{
           sum2+=arr2;
           j++;
       }
       if(sum1-sum2==0){
           count++;
           sum1=0;
           sum2=0;
       }
    }
    return count==0?-1:count;
