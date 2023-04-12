nnoremap  [b :bprevious<CR>
nnoremap  ]b :bnext<CR>
nnoremap  [B :bfirst<CR>
nnoremap  ]B :blast<CR>
inoremap  <C-a> <Home>
inoremap  <C-e> <End>
inoremap  <C-f> <Right>
inoremap  <C-b> <Left>
inoremap ,, struct<space>object*
set nu
let g:user_emmet_install_global = 0
autocmd FileType c,c++ noremap <buffer> <c-k> <Esc>I/*<Esc>A*/<Esc>
let g:snipMate = { 'snippet_version' : 1 }

set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

