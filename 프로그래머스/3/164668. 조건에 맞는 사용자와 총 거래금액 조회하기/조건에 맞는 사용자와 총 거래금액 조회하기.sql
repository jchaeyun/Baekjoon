-- JOIN으로 합쳐야하나?
-- 완료된 중고거래&거래 총 금액 70만원
-- 메인 쿼리에서 완료된 중고거래 거르고
-- 서브 쿼리에서 아이디 그룹화하고 금액 70만원인 아이디 거르고
-- 그 아이디랑 같은 아이디를 골라야하나
-- 메인 그룹핑도 ID 그룹핑
SELECT
    U.USER_ID AS USER_ID,
    U.NICKNAME AS NICKNAME,
    SUM(B.PRICE) AS TOTAL_SALES
FROM 
    USED_GOODS_BOARD B
INNER JOIN 
    USED_GOODS_USER U ON B.WRITER_ID=U.USER_ID -- 아이디 같은 것 기준으로 연결
WHERE
    B.STATUS='DONE' -- 판매 완료
    AND
    U.USER_ID IN -- 금액 70만원 이상인 아이디
    (SELECT B.WRITER_ID
    FROM USED_GOODS_BOARD B
    WHERE B.STATUS='DONE'
    GROUP BY B.WRITER_ID
    HAVING SUM(B.PRICE)>=700000
    )
GROUP BY
    U.USER_ID,U.NICKNAME 
ORDER BY
    SUM(B.PRICE) ASC
    

