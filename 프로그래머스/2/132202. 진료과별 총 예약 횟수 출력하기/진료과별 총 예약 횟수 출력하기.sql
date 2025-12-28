-- 코드를 입력하세요
SELECT
    MCDP_CD AS '진료과코드',
    COUNT(APNT_NO) AS '5월예약건수'
FROM
    APPOINTMENT
WHERE
    APNT_YMD>='2022-05-01'
    AND
    APNT_YMD<'2022-06-01'
/*
APNT_YMD 컬럼에 인덱스(Index)가 걸려 있어도, YEAR()나 MONTH() 같은 함수로 컬럼을 감싸버리면 DB는 인덱스를 타지 못하고 풀 스캔(Full Table Scan)을 할 가능성이 매우 높습니다(느림).
*/
GROUP BY
    MCDP_CD
ORDER BY
    COUNT(APNT_NO) ASC,
    MCDP_CD ASC
/*
SQL은 코드를 작성하는 순서(SELECT -> FROM -> WHERE...)와 실행되는 순서가 
다릅니다.

실행 순서: FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY

따라서 ORDER BY에서는 SELECT 절에서 만든 별칭('5월예약건수')을 사용할 수 있지만, 만약 WHERE나 GROUP BY에서 별칭을 쓰려고 했다면 에러가 났을 것입니다.*/