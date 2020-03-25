#lang racket

(define (accumulate op initial seq)
  (if (null? seq)
      initial
      (op (car seq)
          (accumulate op initial (cdr seq)))))

(define (flatmap proc seq)
  (accumulate append null (map proc seq)))

(define (queens board-size)
  (define (queen-cols k)
    (if (= k 0)
        (list empty-board)
        (filter
         (lambda (positions) (safe? k positions))
         (flatmap
          (lambda (new-row)
            (map (lambda (rest-of-queens)
                   (adjoin-position new-row k rest-of-queens))
                 (queen-cols (- k 1))))
          (enumerate-interval 1 board-size)))))
  (queen-cols board-size))

(define (enumerate-interval low high)
  (if (> low high)
      null
      (cons low (enumerate-interval (+ low 1) high))))

(define empty-board null)

(define (adjoin-position row vertical rest-of-queens)
  (append (list (list row vertical)) rest-of-queens))

(define (safe? vertical rest-of-queens)
  (define (same-row? a b)
    (= (car a) (car b)))
  (define (same-diagonal? a b)
    (= (abs (- (car a) (car b)))
       (abs (- (cadr a) (cadr b)))))
  (define (check-for-safety current-queen rest-of-queens)
    (cond ((null? rest-of-queens) #t) 
          ((and (not (same-row? current-queen (car rest-of-queens)))
                (not (same-diagonal? current-queen (car rest-of-queens)))) 
           (check-for-safety current-queen (cdr rest-of-queens)))
          (else #f)))
  (check-for-safety (car rest-of-queens) (cdr rest-of-queens)))