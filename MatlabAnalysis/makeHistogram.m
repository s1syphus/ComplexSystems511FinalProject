fid = fopen('./Output/daWikiSccCountOutput');
da = fscanf(fid, '%g');
B = hist(da, [2 3 4 5 6 7 8 9 10 20 100]);
B
bar([2 3 4 5 6 7 8 9 10 20 100],B)
set(gca,'Yscale','log')