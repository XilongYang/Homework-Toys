" All system-wide defaults are set in $VIMRUNTIME/archlinux.vim (usually just
" /usr/share/vim/vimfiles/archlinux.vim) and sourced by the call to :runtime
" you can find below.  If you wish to change any of those settings, you should
" do it in this file (/etc/vimrc), since archlinux.vim will be overwritten
" everytime an upgrade of the vim packages is performed.  It is recommended to
" make changes after sourcing archlinux.vim since it alters the value of the
" 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages.
runtime! archlinux.vim

" If you prefer the old-style vim functionalty, add 'runtime! vimrc_example.vim'
" Or better yet, read /usr/share/vim/vim80/vimrc_example.vim or the vim manual
" and configure vim to your own liking!

" do not load defaults if ~/.vimrc is missing
"let skip_defaults_vim=1

set nocompatible
syntax on
set showmode
set showcmd
set mouse=a
set encoding=utf-8
set t_Co=256
filetype off
set autoindent
set tabstop=2
set shiftwidth=4
set expandtab
set softtabstop=4
set number
set wrap
set linebreak
set wrapmargin=2
set laststatus=1
set ruler
set showmatch
set hlsearch
set incsearch
set ignorecase
set smartcase
set nobackup
set noswapfile
set undofile
set noerrorbells
set visualbell
set history=1000
set autoread
set wildmenu
set wildmode=longest:list,full
set textwidth=2000
set ttimeoutlen=100