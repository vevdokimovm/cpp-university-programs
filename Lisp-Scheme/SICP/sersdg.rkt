#lang racket

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))

(define (istree? tree)
  (if (not (pair? tree))
      tree
      (append (list (istree? (car tree)))
              (list (istree? (cdr tree))))))

(define (enumerate-tree tree)
  (cond ((null? tree) null)
        ((not (pair? tree)) (list tree))
        (else (append (enumerate-tree (car tree))
                      (enumerate-tree (cdr tree))))))

;(define (count-leaves t)
;  (accumulate (lambda (x y) (+ 1 y)) 0 (map (lambda (x) x) (enumerate-tree t))))
                                               

(define (count-leaves t)
  (accumulate +
              0
              (map (lambda (x) 
                     (if (pair? x)
                         (count-leaves x)
                         1))
                   t)))