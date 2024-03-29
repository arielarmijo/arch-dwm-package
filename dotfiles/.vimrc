" VIM Configuration file
set mouse=a
set nocompatible

" Display
set title                 " Update the title of your window or your terminal
set number								" Show current line number
set relativenumber        " Display line numbers
"set ruler                " Display cursor position
set showcmd
set wrap                  " Wrap lines when they are too long
set wildmenu
set laststatus=2
set noshowmode
"set showtabline=2
set scrolloff=5           " Display at least 3 lines around you cursor (for scrolling)
set timeoutlen=1000
set ttimeoutlen=10

" Tabs and spaces configuration
set autoindent
set expandtab
set tabstop=2
set shiftwidth=2

" Theme
set background=dark
let g:solarized_termtrans=1
colorscheme solarized

let g:lightline = {
	\ 'colorscheme': 'powerline',
	\ 'active': {
  \		'left': [ [ 'mode', 'paste' ],
	\             [ 'readonly', 'filename', 'modified' ] ] },
	\ 'inactive': {
  \		'left': [ [ 'filename' ] ] },
	\ 'tabline': {
	\		'left': [['tabs']],
	\		'right': [['bufnum']] }
	\}

" Transparent status line background
let s:palette = g:lightline#colorscheme#{g:lightline.colorscheme}#palette
let s:palette.normal.middle = [ [ 'NONE', 'NONE', 'NONE', 'NONE' ] ]
let s:palette.insert.middle = [ [ 'NONE', 'NONE', 'NONE', 'NONE' ] ]
let s:palette.replace.middle = [ [ 'NONE', 'NONE', 'NONE', 'NONE' ] ]
let s:palette.inactive.middle = [ [ 'NONE', 'NONE', 'NONE', 'NONE' ] ]
let s:palette.tabline.middle = [ [ 'NONE', 'NONE', 'NONE', 'NONE' ] ]
let s:palette.tabline.tabsel = [ [ '#d0d0d0', '#5f8787', 231, 236, 'bold' ] ]
let s:palette.tabline.right = [ [ '#d0d0d0', '#5f8787', 231, 'NONE', 'NONE' ] ]
let s:palette.tabline.left = [ [ '#d0d0d0', '#5f8787', 252, 233, 'NONE' ] ]

" Search
set ignorecase            " Ignore case when searching
set smartcase             " If there is an uppercase in your search term
set incsearch             " Highlight search results when typing
set hlsearch              " Highlight search results

" Hide buffer (file) instead of abandoning when switching to another buffer
set hidden

syntax enable
filetype plugin indent on
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o

set spelllang=es
set foldmethod=marker

" Custom maps
nnoremap <Space> za
nnoremap <F2> :set hlsearch!<CR>
nnoremap <F3> :call ToggleFoldMethod()<CR>
nnoremap <C-n> :NERDTreeToggle<CR>

function ToggleFoldMethod()
	if &foldmethod == "marker"
		set foldmethod=syntax
	elseif &foldmethod == "syntax"
		set foldmethod=indent
	elseif &foldmethod == "indent"
		set foldmethod=marker
	endif
	echo join(["foldmethod", &foldmethod], "=")
endfunction

" Plugins
call plug#begin()
Plug 'preservim/nerdtree'
call plug#end()

