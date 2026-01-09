
SELECT
    COUNT(*) AS FISH_COUNT,
    MAX(IFNULL(LENGTH,10)) AS MAX_LENGTH,
    FISH_TYPE
FROM
    FISH_INFO
GROUP BY
        FISH_TYPE
HAVING 
    AVG(IFNULL(LENGTH,10))>=33
ORDER BY
        FISH_TYPE ASC
    /*
3. 질문에 대한 답변
"그룹핑해도 개수를 셀 수 있나?"

네, 무조건 셀 수 있습니다! 오히려 COUNT는 그룹핑이랑 단짝 친구입니다.

GROUP BY FISH_TYPE을 하는 순간, DB는 물고기들을 종류별로 바구니에 담습니다.

그 상태에서 COUNT(*)를 하면 **"그 바구니에 몇 마리 들었어?"**라고 묻는 것이므로 정확하게 개수가 나옵니다.

4. 시각적 정리 (Mental Model)
FROM: 물고기 전체 데이터를 가져옵니다.

GROUP BY: FISH_TYPE 별로 바구니를 만들어 담습니다. (도미 바구니, 광어 바구니...)

HAVING: 각 바구니의 평균 무게를 재봅니다.

"도미 바구니 평균 30cm? 탈락." (버림)

"광어 바구니 평균 40cm? 합격." (남김)

SELECT: 남은 바구니에 대해서 개수(COUNT)와 최대 길이(MAX)를 적어서 보여줍니다.

결론: 서브쿼리로 복잡하게 WHERE (A,B) IN ... 할 필요 없이, **"그룹의 특징(평균, 합계 등)으로 필터링할 땐 무조건 HAVING이다"**라고 생각하시면 레벨 3 문제는 거의 다 풀립니다!*/