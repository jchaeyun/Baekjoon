-- 코드를 작성해주세요
SELECT
    ID,
    CASE NTILE(4) OVER (ORDER BY SIZE_OF_COLONY DESC)
        WHEN 1 THEN 'CRITICAL'
        WHEN 2 THEN 'HIGH'
        WHEN 3 THEN 'MEDIUM'
        WHEN 4 THEN 'LOW'
    END AS COLONY_NAME
FROM 
    ECOLI_DATA
ORDER BY
    ID ASC
    
/*
NTILE(4)의 의미:

"전체 데이터를 4등분 해라."

문제에서 데이터 총수가 4의 배수라고 했으므로, 정확히 똑같은 개수만큼 그룹이 나뉩니다.

OVER (ORDER BY ...)의 역할:

누구를 기준으로? SIZE_OF_COLONY가 큰 순서대로(DESC).

즉, 제일 큰 덩어리들이 1번 그룹을 가져가고, 제일 작은 덩어리들이 4번 그룹을 가져갑니다.

CASE 문의 활용:

NTILE이 뱉어낸 숫자(1, 2, 3, 4)를 문제에서 요구한 문자열('CRITICAL' 등)로 바꿔줍니다. 아까 배우신 '딱 떨어지는 값일 때' 쓰는 CASE 문법이 여기서 쓰입니다.
*/
