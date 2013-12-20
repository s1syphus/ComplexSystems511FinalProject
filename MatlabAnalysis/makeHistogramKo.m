fid = fopen('./Output/koWikiSccCountOutput');
ko = fscanf(fid, '%g');
B = hist(ko, [2 3 4 5 6 7 8 9 10 20 100]);
B
C = B./sum(B) * 100;
C
bar([2 3 4 5 6 7 8 9 10 20 100],B)
set(gca,'Yscale','log')
set(gca, 'Xscale','log')