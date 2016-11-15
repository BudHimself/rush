syn on
set number
set ruler
set cindent
set smartindent
set autoindent
inoremap ( ()<left>
inoremap { {<enter><tab><backspace><enter>}<up><right>
inoremap [ []<left>
set tabstop=4
set shiftwidth=4
autocmd BufEnter * highlight UnwantedSpaces ctermbg=red guibg=#red
autocmd BufEnter * match UnwantedSpaces /\s\+$/
let @/='  '
set hls

autocmd bufnewfile *.c so ~/header.txt
autocmd bufnewfile *.c exe "1," . 10 . "g/File Name : */s//File Name : " .expand("%")
autocmd bufnewfile *.c exe "1," . 10 . "g/By : */s//By : " . $USER . $MAIL ("%")
autocmd bufnewfile *.c exe "1," . 10 . "g/Created Date : */s//Created Date : " .strftime("%d-%m-%Y")
autocmd bufwritepre,filewritepre *.c execute "normal ma"
autocmd bufwritepre,filewritepre *.c exe "1," . 10 . "g/Updated : */s//Updated : " .strftime("%c")
autocmd bufwritepre,filewritepost *.c execute "normal `a" 
