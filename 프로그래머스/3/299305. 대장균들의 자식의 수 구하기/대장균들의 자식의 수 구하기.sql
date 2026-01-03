-- 코드를 작성해주세요
SELECT
    PARENT.ID AS ID,
    COUNT(CHILD.ID) AS CHILD_COUNT
FROM
    ECOLI_DATA PARENT
LEFT JOIN
    ECOLI_DATA CHILD ON CHILD.PARENT_ID=PARENT.ID
GROUP BY
   PARENT.ID
ORDER BY
    ID ASC
/*
체크 포인트 (Human-AI 협업 관점):

IFNULL 제거: COUNT(컬럼명) 함수는 값이 NULL일 경우 자동으로 0을 반환합니다. 
따라서 IFNULL을 감쌀 필요가 없어 코드가 더 간결해집니다.

주의사항: 만약 COUNT(*)를 쓰면 LEFT JOIN으로 생성된 NULL 행도 1로 카운트하는 오류가 발생합니다. 반드시 COUNT(CHILD.ID)처럼 오른쪽 테이블의 PK를 지정해야 정확히 0이 나옵니다.


<서브쿼리 사용 (의도가 더 명확한 방법)>
조인이 헷갈리거나, "각 ID별로 자식 수를 센다"는 의미를 명확히 하고 싶다면 SELECT 절에 서브쿼리를 넣는 것이 가독성이 더 좋을 수 있습니다.

SQL

SELECT
    ID,
    (SELECT COUNT(*) FROM ECOLI_DATA WHERE PARENT_ID = M.ID) AS CHILD_COUNT
FROM
    ECOLI_DATA M
ORDER BY
    ID ASC;
    
    
작동 순서 (Row-by-Row)
데이터베이스는 [C](FROM ECOLI_DATA M)에 있는 모든 줄을 하나씩 훑으면서 내려갑니다.

첫 번째 줄 (ID = 1) 처리:

[A] ID를 가져옵니다. -> 1 확보.

[B] 서브쿼리 실행: "전체 데이터에서 PARENT_ID가 **1**인 녀석이 몇 명이야?"라고 묻습니다.

계산: ID 3이 있으므로 **1명**이라고 답합니다.

결과 기록: 1 | 1

두 번째 줄 (ID = 2) 처리:

[A] ID를 가져옵니다. -> 2 확보.
[B] 서브쿼리 실행: "전체 데이터에서 PARENT_ID가 2인 녀석이 몇 명이야?"

계산: 아무도 없습니다. COUNT는 0을 반환합니다.

결과 기록: 2 | 0 (★ 여기서 NULL이 아니라 0이 나옵니다)

세 번째 줄 (ID = 3) 처리:

[A] ID를 가져옵니다. -> 3 확보.
[B] 서브쿼리 실행: "전체 데이터에서 PARENT_ID가 3인 녀석이 몇 명이야?"

계산: 아무도 없습니다.

결과 기록: 3 | 0
*/