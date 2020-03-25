#lang racket


;operation wiht list

(define (map proc items)
  (if (null? items)
      null
      (cons (proc (car items))
            (map proc (cdr items)))))

(define square (lambda (x) (* x x)))

(define (square-tree tree)
  (map (lambda (sub-tree)
         (if (pair? sub-tree)
             (square-tree sub-tree)
             (square sub-tree)))
       tree))


;(define (square-tree tree)
;  (cond ((null? tree) null)
;        ((pair? tree) (cons (square-tree (car tree))
;                            (square-tree (cdr tree))))
;        (else (square tree))))

(define x (list 1
                (list 2 (list 3 4) 5)
                (list 6 7)))