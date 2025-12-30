-- 코드를 작성해주세요

SELECT 
    SUM(G.SCORE) AS SCORE,
    E.EMP_NO AS EMP_NO,
    E.EMP_NAME AS EMP_NAME,
    E.POSITION AS POSITION,
    E.EMAIL AS EMAIL
FROM    
    HR_EMPLOYEES E
INNER JOIN
    HR_DEPARTMENT D ON D.DEPT_ID=E.DEPT_ID -- 첫번째 조인(부서)
INNER JOIN
    HR_GRADE G ON G.EMP_NO=E.EMP_NO -- 두번째 조인(성적)
WHERE
    G.YEAR=2022
GROUP BY
    E.EMP_NO,E.EMP_NAME,E.POSITION,E.EMAIL
HAVING
-- 전체 사원의 2022년 최고 점수를 먼저 구한 후 비교
    SUM(G.SCORE)=(
    SELECT 
        MAX(TOTALSCORE)
    FROM
        (
            SELECT 
                SUM(SCORE) AS TOTALSCORE
            FROM 
                HR_GRADE
            WHERE
                YEAR=2022
            GROUP BY
                EMP_NO
        ) AS MAXTABLE
    )
    
/*두 번의 합치기 (JOIN Syntax):

기존: INNER JOIN ... ON ... AND ... (오류 발생)

수정: INNER JOIN ... ON ... 구문을 명확히 두 번 반복하여 사원(E)-부서(D)-성적(G)을 올바르게 연결했습니다.

상/하반기 합산 (Aggregation):

GROUP BY를 통해 한 사원의 2022년도 데이터(상반기 행 + 하반기 행)를 하나로 묶고, 
SUM(G.SCORE)로 연간 총점을 계산했습니다.

최고점자 필터링 (Logic):

HAVING 절 안에 서브쿼리를 넣어, "내 점수 합계가 전체 사원 중 최고 점수 합계와 같은가?"를 
물어보는 방식으로 1등을 찾아냅니다. (공동 1등도 모두 나옵니다.)


이렇게 짠 이유는 **"SQL의 문법적 강제성(Standard SQL)"**과 "호환성" 때문입니다. 이유를 명확히 설명해 드리겠습니다.

1. AS MaxTable은 왜 붙였나요?
이건 SQL의 문법 규칙(Syntax Rule) 때문입니다.

FROM 절 안에 들어가는 서브쿼리는 DB 입장에서 **"임시 테이블"**로 취급됩니다.

대부분의 DB(MySQL, PostgreSQL, SQL Server 등)는 이 임시 테이블에 **이름표(Alias)**가 없으면 "이 테이블의 이름이 뭐냐? 이름을 지정해라!" 라며 에러(Every derived table must have its own alias)를 뱉습니다.

그래서 아무 의미 없는 이름(MaxTable, A, T 등)이라도 형식상 붙여줘야 코드가 돌아갑니다.

2. EMP_NO만 있으면 되는데 왜 다 적었나요?
"표준 SQL의 엄격한 규칙" 때문입니다.

(1) 기계의 고지식함 (ONLY_FULL_GROUP_BY)
인간은 "사원번호가 같으면 당연히 이름도 같지"라고 생각하지만, 엄격한 SQL 모드(특히 Oracle, SQL Server, 최신 MySQL 설정)에서는 이렇게 따집니다.

"당신이 SELECT에서 EMP_NAME을 출력하라고 했군요. 그런데 GROUP BY 기준에는 EMP_NO밖에 없네요? 만약 같은 사원번호에 이름이 다른 데이터가 있으면 어떡하죠? (그런 일이 없다는 걸 기계는 모름) 안전하지 않으니 에러를 내겠습니다."

따라서 SELECT 절에 있는 모든 컬럼은 집계함수(SUM, MAX)로 감싸거나, 아니면 GROUP BY 절에 명시해야만 에러가 나지 않습니다. 그래서 방어적으로 다 적어드린 것입니다.*/
