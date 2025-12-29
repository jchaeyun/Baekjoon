-- 코드를 입력하세요
SELECT /*(가격/10000)을 내림하고 다시 10000을 곱해 '가격대'를 만듦*/
    
    TRUNCATE(PRICE/10000,0)*10000 AS PRICE_GROUP,
    COUNT(PRODUCT_ID) AS PRODUCTS
FROM
    PRODUCT
GROUP BY    
    PRICE_GROUP /*위에서 만든 별칭으로 그룹핑,mysql에서만 됨*/
    /*TRUNCATE(PRICE / 10000, 0) * 10000; 이게 표준방식임*/
ORDER BY
    PRICE_GROUP ASC
