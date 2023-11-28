nnoremap  [b :bprevious<CR>
nnoremap  ]b :bnext<CR>
nnoremap  [B :bfirst<CR>
nnoremap  ]B :blast<CR>
inoremap  <C-a> <Home>
inoremap  <C-e> <End>
inoremap  <C-f> <Right>
inoremap  <C-b> <Left>
"inoremap ,, struct<space>object*
"nnoremap ,, :e ~/.vim_runtime/my_configs.vim<CR>
nnoremap <leader>q :cclose<CR>
nnoremap <leader>c :close<CR>
set nu
set nopaste
let g:user_emmet_install_global = 0
autocmd FileType c,c++ noremap <buffer> <c-k> <Esc>I/*<Esc>A*/<Esc>
let g:snipMate = { 'snippet_version' : 1 }

set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

inoremap <c-u> <c-g>u<c-u>
inoremap <c-w> <c-g>u<c-w>

"https://github.com/TianpingHsu/Learn-Vim/blob/master/ch10_undo.md
set undodir=~/.vim/undo
set undofile

"https://github.com/TianpingHsu/Learn-Vim/blob/master/ch11_visual_mode.md
set nrformats+=alpha

" `<    Go to the first place of the previous visual mode highlight
" `>    Go to the last place of the previous visual mode highlight
" running Ctrl-O while in the insert mode lets you execute a normal mode command.

" SEARCH and REPLACE
" https://github.com/TianpingHsu/Learn-Vim/blob/master/ch12_search_and_substitute.md
"You can use \C pattern anywhere in your search term to tell Vim that the subsequent search term will be case sensitive.



" PLUGINS
"https://github.com/junegunn/vim-peekaboo
"https://github.com/ycm-core/YouCompleteMe

